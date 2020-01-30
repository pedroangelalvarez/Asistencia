import gi
gi.require_version("Gtk", "3.0")
from gi.repository import Gtk, Gdk, GObject
import time

#https://jayrambhia.com/blog/opencv-with-pygtk

class gui():

    def __init__(self):
        self.window = Gtk.Window()
        self.window.connect('delete-event', Gtk.main_quit)
        grid = Gtk.Grid()
        self.window.add(grid)

        quitBtn = Gtk.Button(label="Salir")
        quitBtn.set_size_request(80, 30)
        quitBtn.connect("clicked", self.on_button_clicked)
        grid.attach(quitBtn, 0, 0, 1, 1)

        oneBtn = Gtk.Button(label="1")
        oneBtn.set_size_request(40, 40)
        oneBtn.connect("clicked", self.inputNumber)
        grid.attach(oneBtn, 1, 1, 1, 1)

        twoBtn = Gtk.Button(label="2")
        twoBtn.set_size_request(40, 40)
        twoBtn.connect("clicked", self.inputNumber)
        grid.attach(twoBtn, 2, 1, 1, 1)

        threeBtn = Gtk.Button(label="3")
        threeBtn.set_size_request(40, 40)
        threeBtn.connect("clicked", self.inputNumber)
        grid.attach(threeBtn, 3, 1, 1, 1)

        fourBtn = Gtk.Button(label="4")
        fourBtn.set_size_request(40, 40)
        fourBtn.connect("clicked", self.inputNumber)
        grid.attach(fourBtn, 1, 2, 1, 1)

        fiveBtn = Gtk.Button(label="5")
        fiveBtn.set_size_request(40, 40)
        fiveBtn.connect("clicked", self.inputNumber)
        grid.attach(fiveBtn, 2, 2, 1, 1)

        sixBtn = Gtk.Button(label="6")
        sixBtn.set_size_request(40, 40)
        sixBtn.connect("clicked", self.inputNumber)
        grid.attach(sixBtn, 3, 2, 1, 1)

        sevenBtn = Gtk.Button(label="7")
        sevenBtn.set_size_request(40, 40)
        sevenBtn.connect("clicked", self.inputNumber)
        grid.attach(sevenBtn, 1, 3, 1, 1)

        eightBtn = Gtk.Button(label="8")
        eightBtn.set_size_request(40, 40)
        eightBtn.connect("clicked", self.inputNumber)
        grid.attach(eightBtn, 2, 3, 1, 1)

        nineBtn = Gtk.Button(label="9")
        nineBtn.set_size_request(40, 40)
        nineBtn.connect("clicked", self.inputNumber)
        grid.attach(nineBtn, 3, 3, 1, 1)

        self.window.set_border_width(10)
        self.window.set_title("ASISTENCIA")
        self.window.set_decorated(False)
        self.window.set_default_size(600, 400)
        self.window.connect("destroy", Gtk.main_quit)


        self.labelTime = Gtk.Label()
        grid.attach(self.labelTime, 0, 1, 1, 1)
        self.label = Gtk.Label()
        grid.attach(self.label, 1, 0, 1, 1)
        
        self.window.show_all()
        GObject.timeout_add(200, self.update)
        Gtk.main()

    def inputNumber(self,button):
        text = self.label.get_label() + button.get_label()
        self.label.set_text(text)

    def on_button_clicked(self, widget):
        Gtk.main_quit()

    def update(self):
        self.labelTime.set_text(time.strftime('%H:%M:%S'))
        return True  #needed to keep the update method in the schedule

if __name__ == '__main__':
    gui = gui()