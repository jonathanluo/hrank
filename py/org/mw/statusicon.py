#!/usr/bin/python
#
# https://stackoverflow.com/questions/7397969/how-to-create-a-status-icon-in-either-notification-area-or-indicator-applet
# https://web.archive.org/web/20130225180200/http://learngtk.org:80/pygtk-tutorial/examples/statusicon.py
#
import gtk

class StatusIcon:
    def __init__(self):
        self.statusicon = gtk.StatusIcon()
        self.statusicon.set_from_stock(gtk.STOCK_HOME) 
        self.statusicon.connect("popup-menu", self.right_click_event)
        self.statusicon.set_tooltip("StatusIcon Example")

        window = gtk.Window()
        window.connect("destroy", lambda w: gtk.main_quit())
        window.show_all()

    def right_click_event(self, icon, button, time):
        menu = gtk.Menu()

        about = gtk.MenuItem("About")
        quit1 = gtk.MenuItem("Quit")

        about.connect("activate", self.show_about_dialog)
        quit1.connect("activate", gtk.main_quit)

        menu.append(about)
        menu.append(quit1)
        menu.show_all()

        menu.popup(None, None, gtk.status_icon_position_menu, button, time, self.statusicon)

    def show_about_dialog(self, widget):
        about_dialog = gtk.AboutDialog()

        about_dialog.set_destroy_with_parent(True)
        about_dialog.set_name("StatusIcon Example")
        about_dialog.set_version("1.0")
        about_dialog.set_authors(["Andrew Steele"])

        about_dialog.run()
        about_dialog.destroy()

StatusIcon()
gtk.main()
