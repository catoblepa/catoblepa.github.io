#!/usr/bin/env python2.4
# -*- coding: latin-1 -*-
# Una GUI per Festival
# Programma in Python creato da Truffa Davide
# www.catoblepa.org  davide@catoblepa.org

import os, sys, string, gtk, pygtk

def sostituisci(self):
  self=self.replace("à","a'")
  self=self.replace("è","e'")
  self=self.replace("é","e'")
  self=self.replace("ì","i'")
  self=self.replace("ò","o'")
  self=self.replace("ù","u'")
  return(self)

def pulisci_testo(*args):
  testo_entry.set_text("")
  testo_entry.grab_focus()

def launch_festival(*args):
  if voce.get_active() == 0 :
    voce_set="(voice_pc_diphone)"
  elif voce.get_active() == 1 :
    voce_set="(voice_lp_diphone)"
  elif voce.get_active() == 2 :
    voce_set="(voice_ked_diphone)"

  testo=sostituisci(testo_entry.get_text())
  comando="echo \"" + voce_set + "(SayText \\\"" + testo + "\\\")\" | /usr/bin/festival"
  os.system(comando)
  
  start=log_buffer.get_start_iter()
  log_buffer.place_cursor(start)
  log_buffer.insert_at_cursor(testo + '\n')
  #print voce.get_active() 
  #print comando


# crea widget
win = gtk.Window()
win.set_title("Festival GUI")
win.set_default_size(320,360)
win.set_border_width(5)
vbox0 = gtk.VBox(False, spacing=5)
testo_entry = gtk.Entry()
hbox0 = gtk.HBox()
pulisci = gtk.Button("Cancella")
leggi = gtk.Button("Leggi")
log_scroll = gtk.ScrolledWindow()
log_scroll.set_policy(gtk.POLICY_AUTOMATIC,gtk.POLICY_AUTOMATIC)
log = gtk.TextView()
voce = gtk.combo_box_new_text()

# disegna finestra
win.add(vbox0)
vbox0.pack_start(testo_entry, 0, 0, 5)
vbox0.pack_start(hbox0, 0, 0)
hbox0.pack_start(pulisci, 1, 1)
hbox0.pack_start(leggi, 1, 1)
vbox0.pack_start(log_scroll, 1, 1)
log_scroll.add_with_viewport(log)
vbox0.pack_start(voce, 0, 0)
win.show_all()

# elenco segnali
leggi.connect('clicked', launch_festival)
pulisci.connect('clicked', pulisci_testo)
win.connect('destroy', gtk.main_quit)
testo_entry.connect('activate', launch_festival)

# opzioni
log_buffer=log.get_buffer()
voce.insert_text(0, "Lingua Italiana - Voce Maschile")
voce.insert_text(1, "Lingua Italiana - Voce Femminile")
voce.insert_text(2, "Lingua Inglese - Voce Maschile")
voce.set_active(0)

gtk.main()
