#!/usr/bin/python

#
# https://stackoverflow.com/questions/6389580/quick-and-easy-trayicon-with-python
#

class TrayIcon:
    def init():

        iconPath = {"Windows":os.path.expandvars("%PROGRAMFILES%/MyProgram/icon.png"),
                      "Linux":"/home/moonwave/workspace/github/jon/lang/py/system_tray/icon.png"}
        if platform.system()=="Linux":
            import gtk
            import appindicator # Ubuntu apt-get install python-appindicator 
    
        # Create an application indicator
        try:
            gtk.gdk.threads_init()
            gtk.threads_enter()
            icon = iconPath[platform.system()]
            indicator = appindicator.Indicator("example-simple-client", "indicator-messages", appindicator.CATEGORY_APPLICATION_STATUS)
            indicator.set_icon(icon)
            indicator.set_status (appindicator.STATUS_ACTIVE)
            indicator.set_attention_icon ("indicator-messages-new")
            menu = gtk.Menu()
    
            menuTitle = "Quit"   
            menu_items = gtk.MenuItem(menuTitle)
            menu.append(menu_items)
            menu_items.connect("activate", TrayIcon.QuitApp, menuTitle)
            menu_items.show()
    
            menuTitle = "About My Program"
            menu_items = gtk.MenuItem(menuTitle)
            menu.append(menu_items)
            menu_items.connect("activate", TrayIcon.AboutApp, menuTitle)
            menu_items.show()   
    
            indicator.set_menu(menu)    
        except:
            pass
    
        # Run the app indicator on the main thread.
        try:
    
            t = threading.Thread(target=gtk.main)
            t.daemon = True # this means it'll die when the program dies.
            t.start()
            #gtk.main()
    
        except:
            pass
        finally:
            gtk.threads_leave()

@staticmethod
def AboutApp(a1,a2):
    gtk.threads_enter()
    dialog = gtk.Dialog("About",
                        None,
                        gtk.DIALOG_MODAL | gtk.DIALOG_DESTROY_WITH_PARENT,
                        (gtk.STOCK_OK, gtk.RESPONSE_ACCEPT))
    label = gtk.Label("My Program v0.0.1, (C)opyright ME 2015. All rights reserved.")
    dialog.vbox.pack_start(label)
    label.show()
    label2 = gtk.Label("example.com\n\nFor more support contact me@gmail.com")
    label2.show()
    dialog.action_area.pack_end(label2)
    response = dialog.run()
    dialog.destroy()
    gtk.threads_leave()

@staticmethod
def QuitApp(a1, a2):
    sys.exit(0)
