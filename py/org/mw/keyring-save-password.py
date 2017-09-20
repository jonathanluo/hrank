#!/usr/bin/env python

import gnomekeyring
#http://references.valadoc.org/#!api=gnome-keyring-1/GnomeKeyring.ItemType
#http://references.valadoc.org/#!api=gnome-keyring-1/GnomeKeyring.store_password_sync


#unlock first
#gnomekeyring.store_password_sync (PasswordSchema schema, string? keyring, string display_name, string password, ...)

#rs = gnomekeyring.store_password_sync (None, "test", "uml", "abc_1989")

#print rs
#item_create_sync (string? keyring, ItemType type, string display_name, AttributeList attributes, string secret, bool update_if_exists, out uint32 item_id)
gnomekeyring.item_create_sync ("test", gnomekeyring.ITEM_GENERIC_SECRET, "uml", {}, "1989_changed", True)
gnomekeyring.item_create_sync ("login", gnomekeyring.ITEM_GENERIC_SECRET, "https://svn.gm.com/svn/SS_AOM_49101", {}, "hope_123", True)
gnomekeyring.item_create_sync ("login", gnomekeyring.ITEM_GENERIC_SECRET, "www.wenxuecity.com", {}, "wc_1979", True)


