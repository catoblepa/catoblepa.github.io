// jquery toggle
$(document).ready(function() {
	//$(".hidden").hide();
	$("li.search").click(function() {
		$("#contacts").hide();
		$("#search").fadeToggle("normal");
	});
	$("li.contacts").click(function() {
		$("#search").hide();
		$("#contacts").fadeToggle("normal");
	});
});
