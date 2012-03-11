/**
 * UGENE - Integrated Bioinformatics Tools.
 * Copyright (C) 2008-2012 UniPro <ugene@unipro.ru>
 * http://ugene.unipro.ru
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */

#include "GTKeyboardDriver.h"

#ifdef _WIN32

#include <windows.h>
#define VIRTUAL_TO_SCAN_CODE 0

#endif //_WIN32

#include <cctype>
#include "GTKeyboardDriver.h"
#include "QtUtils.h"

#define ADD_KEY(name, code) insert(std::pair<QString, int>(name, code))

namespace U2 {

#ifdef _WIN32

void GTKeyboardDriver::keyPress(U2::U2OpStatus &os, int key)
{
    CHECK_SET_ERR_RESULT(key != 0, " Error: key = 0 in GTKeyboardDriver::keyPress()");

    if (isalpha(key) && islower(key)) {
        key = toupper(key);
    }

    INPUT event;
    event.type = INPUT_KEYBOARD;
    event.ki.wVk = key;
    event.ki.wScan = MapVirtualKey(key, VIRTUAL_TO_SCAN_CODE);
    event.ki.dwFlags = 0;
    event.ki.time = 0;
    event.ki.dwExtraInfo = 0;

    SendInput(1, &event, sizeof(event));
}

void GTKeyboardDriver::keyPress(U2::U2OpStatus &os, int key, int modifiers)
{
    CHECK_SET_ERR_RESULT(key != 0, " Error: key = 0 in GTKeyboardDriver::keyPress()");
    CHECK_SET_ERR_RESULT(modifiers != 0, " Error: modifiers = 0 in GTKeyboardDriver::keyPress()");

    if (isalpha(key) && islower(key)) {
        key = toupper(key);
    }

    INPUT event;
    event.type = INPUT_KEYBOARD;
    event.ki.wVk = modifiers;
    event.ki.wScan = MapVirtualKey(modifiers, VIRTUAL_TO_SCAN_CODE);
    event.ki.dwFlags = 0;
    event.ki.time = 0;
    event.ki.dwExtraInfo = 0;

    SendInput(1, &event, sizeof(event));

    event.ki.wVk = key;
    event.ki.wScan = MapVirtualKey(key, VIRTUAL_TO_SCAN_CODE);

    SendInput(1, &event, sizeof(event));
}

void GTKeyboardDriver::keyRelease(U2::U2OpStatus &os, int key)
{
    CHECK_SET_ERR_RESULT(key != 0, " Error: key = 0 in GTKeyboardDriver::keyRelease()");
    
    if (isalpha(key) && islower(key)) {
        key = toupper(key);
    }

    INPUT event;
    event.type = INPUT_KEYBOARD;
    event.ki.wVk = key;
    event.ki.wScan = MapVirtualKey(key, VIRTUAL_TO_SCAN_CODE);
    event.ki.dwFlags = KEYEVENTF_KEYUP;
    event.ki.time = 0;
    event.ki.dwExtraInfo = 0;

    SendInput(1, &event, sizeof(event));
}

void GTKeyboardDriver::keyRelease(U2::U2OpStatus &os, int key, int modifiers)
{
    CHECK_SET_ERR_RESULT(key != 0, " Error: key = 0 in GTKeyboardDriver::keyRelease()");
    CHECK_SET_ERR_RESULT(modifiers != 0, " Error: modifiers = 0 in GTKeyboardDriver::keyRelease()");

    if (isalpha(key) && islower(key)) {
        key = toupper(key);
    }

    INPUT event;
    event.type = INPUT_KEYBOARD;
    event.ki.wVk = modifiers;
    event.ki.wScan = MapVirtualKey(modifiers, VIRTUAL_TO_SCAN_CODE);
    event.ki.dwFlags = KEYEVENTF_KEYUP;
    event.ki.time = 0;
    event.ki.dwExtraInfo = 0;

    SendInput(1, &event, sizeof(event));

    event.ki.wVk = key;
    event.ki.wScan = MapVirtualKey(key, VIRTUAL_TO_SCAN_CODE);

    SendInput(1, &event, sizeof(event));
}

void GTKeyboardDriver::keyClick(U2::U2OpStatus &os, int key)
{
    CHECK_SET_ERR_RESULT(key != 0, " Error: key = 0 in GTKeyboardDriver::keyClick()");
 
    keyPress(os, key);
    Sleep(100);
    keyRelease(os, key);
}

void GTKeyboardDriver::keyClick(U2::U2OpStatus &os, int key, int modifiers)
{
    CHECK_SET_ERR_RESULT(key != 0, " Error: key = 0 in GTKeyboardDriver::keyClick()");
    CHECK_SET_ERR_RESULT(modifiers != 0, " Error: modifiers = 0 in GTKeyboardDriver::keyClick()");

    keyPress(os, modifiers, key);
    Sleep(100);
    keyRelease(os, modifiers, key);
}

void GTKeyboardDriver::keySequence(U2::U2OpStatus &os, QString str)
{
    foreach(QChar ch, str) {
        if(isalpha(ch.toAscii()) && !islower(ch.toAscii())) {
            keyClick(os, key["shift"], ch.toAscii());
        } else {
            keyClick(os, ch.toAscii());
        }
    }
}

void GTKeyboardDriver::keySequence(U2::U2OpStatus &os, QString str, int modifiers)
{
    keyPress(os, modifiers);

    foreach(QChar ch, str) {
        if(isalpha(ch.toAscii()) && !islower(ch.toAscii())) {
            keyClick(os, key["shift"], ch.toAscii());
        } else {
            keyClick(os, ch.toAscii());
        }
    }

    keyRelease(os, modifiers);
}


//#####################################################################################
GTKeyboardDriver::keys::keys()
{
    ADD_KEY("back", VK_BACK);
    ADD_KEY("tab", VK_TAB);
    ADD_KEY("clear", VK_CLEAR);
    ADD_KEY("enter", VK_RETURN);
    ADD_KEY("shift", VK_SHIFT);
    ADD_KEY("rshift", VK_RSHIFT);
    ADD_KEY("lshift", VK_LSHIFT);
    ADD_KEY("ctrl", VK_CONTROL);
    ADD_KEY("rctrl", VK_RCONTROL);
    ADD_KEY("lctrl", VK_LCONTROL);
    ADD_KEY("menu", VK_MENU);
    ADD_KEY("lmenu", VK_LMENU);
    ADD_KEY("rmenu", VK_RMENU);
    ADD_KEY("pause", VK_PAUSE);
    ADD_KEY("capital", VK_CAPITAL);
    ADD_KEY("esc", VK_ESCAPE);
    ADD_KEY("space", VK_SPACE);
    ADD_KEY("left", VK_LEFT);
    ADD_KEY("up", VK_UP);
    ADD_KEY("right", VK_RIGHT);
    ADD_KEY("down", VK_DOWN);
    ADD_KEY("insert", VK_INSERT);
    ADD_KEY("delete", VK_DELETE);
    ADD_KEY("help", VK_HELP);
    ADD_KEY("f1", VK_F1);
    ADD_KEY("f2", VK_F2);
    ADD_KEY("f3", VK_F3);
    ADD_KEY("f4", VK_F4);
    ADD_KEY("f5", VK_F5);
    ADD_KEY("f6", VK_F6);
    ADD_KEY("f7", VK_F7);
    ADD_KEY("f8", VK_F8);
    ADD_KEY("f9", VK_F9);
    ADD_KEY("f10", VK_F10);
    ADD_KEY("f12", VK_F12);

// feel free to add other keys
// macro VK_* defined in WinUser.h
}

int GTKeyboardDriver::keys::operator [] (QString str) const
{
    keys::const_iterator it = this -> find(str.toLower());
    if (it == end()) {
        return 0;
    }
    return it -> second;
}

GTKeyboardDriver::keys GTKeyboardDriver::key;

#endif // _WIN32
} //namespace
