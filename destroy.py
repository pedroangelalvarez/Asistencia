import gi
gi.require_version("Gtk", "3.0")
from gi.repository import Gtk

class destroy:
    def on_close_clicked(self, button):
        print("Closing application")
        Gtk.main_quit()