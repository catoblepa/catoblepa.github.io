/* genmon.c -- Generic monitor plugin for fbpanel
 *
 * Copyright (C) 2007 Davide Truffa <davide@catoblepa.org>
 * 
 * This plugin is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 dated June, 1991.
 * 
 * It is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.

Copy these lines in your .fbpanel/default:

# Generic Monitor -- display the output of a program/script
#                    into the panel
#   Options:
#   Command     = program/script to provide the text to display on the
#                 panel
#   PollingTime = in seconds, default is 1 second 
#   TextSize    = xx-small, x-small, small, medium, large, x-large or
#                 xx-large
#   TextColor   = an RGB color specification such as #00FF00 or a color
#                  name such as black, blue or red

Plugin {
    type = genmon
    config {
        Command = echo MemFree: $(grep "MemFree" /proc/meminfo|cut -b 13-30)
        PollingTime = 1
        TextSize = medium
        TextColor = darkblue
    }
}

*/

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "panel.h"
#include "misc.h"
#include "plugin.h"

//#define DEBUG
#include "dbg.h"

typedef struct {
    int time;
    int timer;
    char *command;
    char *textsize;
    char *textcolor;
    GtkWidget *main;
} genmon;


static int
text_update(genmon *gm)
{
    FILE *fp;  
    char text[256];
    char *markup;
    ENTER;
    if ( *gm->command != 0) {
        fp = popen(gm->command, "r");
        fgets(text, sizeof(text), fp);
        pclose(fp);
        text[strlen(text) - 1] = '\0';
        
        if ( *text != 0) {
            markup = g_markup_printf_escaped ("<span size='%s' foreground='%s'>%s</span>",
                gm->textsize, gm->textcolor, text);
            gtk_label_set_markup (GTK_LABEL(gm->main), markup);
        }
    }
    RET(1);
}

  
static void
genmon_destructor(plugin *p)
{
    genmon *gm = (genmon *)p->priv;

    ENTER;
    gm = (genmon *) p->priv;
    if (gm->timer) {
        g_source_remove(gm->timer);
    }
    g_free(gm);
    RET();
}


static int
genmon_constructor(plugin *p)
{
    genmon *gm;
    line s;

    ENTER;
    gm = g_new0(genmon, 1);
    g_return_val_if_fail(gm != NULL, 0);
    p->priv = gm;
    gm->command = "";
    gm->time = 1;
    gm->textsize = "medium";
    gm->textcolor = "darkblue";

    s.len = 256;
    while (get_line(p->fp, &s) != LINE_BLOCK_END) {
        if (s.type == LINE_NONE) {
            ERR( "genmon-plugin: illegal token %s\n", s.str);
            goto error;
        }
        if (s.type == LINE_VAR) {
            if (!g_ascii_strcasecmp(s.t[0], "Command")) {
                gm->command = g_strdup(s.t[1]);
            } else if (!g_ascii_strcasecmp(s.t[0], "PollingTime")) {
                gm->time = strtol(s.t[1],NULL,10);
            } else if (!g_ascii_strcasecmp(s.t[0], "TextSize")) {
                gm->textsize = g_strdup(s.t[1]);
            } else if (!g_ascii_strcasecmp(s.t[0], "TextColor")) {
                gm->textcolor = g_strdup(s.t[1]);
            } else {
                ERR( "genmon-plugin: unknown var %s\n", s.t[0]);
                goto error;
            }
        }
    }
    if (gm->time == 0 ) {
      ERR( "genmon-plugin: bad PollingTime, please check your configuration.\n");
      goto error;
    }
    gm->main = gtk_label_new("bad parameters");
    text_update(gm);
    gtk_container_set_border_width (GTK_CONTAINER (p->pwid), 1);
    gtk_container_add(GTK_CONTAINER(p->pwid), gm->main);
    gtk_widget_show_all(p->pwid);
    gm->timer = g_timeout_add(gm->time*1000, (GSourceFunc) text_update, (gpointer)gm);
    
    RET(1);

    error:
    genmon_destructor(p);
    RET(0);
}


plugin_class genmon_plugin_class = {
    fname: NULL,
    count: 0,

    type : "genmon",
    name : "Generic Monitor",
    version: "0.3",
    description : "Display the output of a program/script into the panel",

    constructor : genmon_constructor,
    destructor  : genmon_destructor,
};
