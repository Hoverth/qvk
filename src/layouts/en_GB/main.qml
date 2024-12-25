// with help from https://forum.qt.io/topic/93279/how-to-custom-qml-virtual-keyboard/14

import QtQuick
import QtQuick.VirtualKeyboard
import QtQuick.VirtualKeyboard.Components
import QtQuick.Layouts

KeyboardLayout {
    inputMode: InputEngine.InputMode.Latin
    keyWeight: 160
    readonly property real normalKeyWidth: normalKey.width
    readonly property real functionKeyWidth: mapFromItem(normalKey, normalKey.width / 2, 0).x

    KeyboardRow {
        Key {
            key: Qt.Key_QuoteLeft
            text: "`"
        }
        Key {
            key: Qt.Key_1
            text: "1"
        }
        Key {
            key: Qt.Key_2
            text: "2"
        }
        Key {
            key: Qt.Key_3
            text: "3"
        }
        Key {
            key: Qt.Key_4
            text: "4"
        }
        Key {
            key: Qt.Key_5
            text: "5"
        }
        Key {
            key: Qt.Key_6
            text: "6"
        }
        Key {
            key: Qt.Key_7
            text: "7"
        }
        Key {
            key: Qt.Key_8
            text: "8"
        }
        Key {
            key: Qt.Key_9
            text: "9"
        }
        Key {
            key: Qt.Key_0
            text: "0"
        }
        Key {
            key: Qt.Key_Minus
            text: "-"
        }
        Key {
            key: Qt.Key_Equal
            text: "="
        }
        BackspaceKey { // This seems to work fine so we'll keep it
            weight: functionKeyWidth
            Layout.fillWidth: false
        }
    }
    KeyboardRow {
        Key {
            key: Qt.Key_Tab
            text: "Tab"
        }
        Key {
            key: Qt.Key_Q
            text: "q"
        }
        Key {
            id: normalKey
            key: Qt.Key_W
            text: "w"
        }
        Key {
            key: Qt.Key_E
            text: "e"
        }
        Key {
            key: Qt.Key_R
            text: "r"
        }
        Key {
            key: Qt.Key_T
            text: "t"
        }
        Key {
            key: Qt.Key_Y
            text: "y"
        }
        Key {
            key: Qt.Key_U
            text: "u"
        }
        Key {
            key: Qt.Key_I
            text: "i"
        }
        Key {
            key: Qt.Key_O
            text: "o"
        }
        Key {
            key: Qt.Key_P
            text: "p"
        }
        Key {
            key: Qt.Key_BracketLeft
            text: "["
        }
        Key {
            key: Qt.Key_BracketRight
            text: "]"
        }
        Key {
            key: Qt.Key_Backslash
            text: "\\"
        }
    }
    KeyboardRow {
        Key {
            key: Qt.Key_CapsLock
            text: "Caps"
        }
        Key {
            key: Qt.Key_A
            text: "a"
        }
        Key {
            key: Qt.Key_S
            text: "s"
        }
        Key {
            key: Qt.Key_D
            text: "d"
        }
        Key {
            key: Qt.Key_F
            text: "f"
        }
        Key {
            key: Qt.Key_G
            text: "g"
        }
        Key {
            key: Qt.Key_H
            text: "h"
        }
        Key {
            key: Qt.Key_J
            text: "j"
        }
        Key {
            key: Qt.Key_K
            text: "k"
        }
        Key {
            key: Qt.Key_L
            text: "l"
        }
        Key {
            key: Qt.Key_Semicolon
            text: ";"
        }
        Key {
            key: Qt.Key_Apostrophe
            text: "'"
        }
        EnterKey {
            weight: functionKeyWidth
            Layout.fillWidth: false
        }
    }
    KeyboardRow {
        Key {
            key: Qt.Key_Shift
            text: "Shift"
            weight: functionKeyWidth
            functionKey: true
            // TODO make these keys sticky/toggleable
            Layout.fillWidth: false
        }
        Key {
            key: Qt.Key_Z
            text: "z"
        }
        Key {
            key: Qt.Key_X
            text: "x"
        }
        Key {
            key: Qt.Key_C
            text: "c"
        }
        Key {
            key: Qt.Key_V
            text: "v"
        }
        Key {
            key: Qt.Key_B
            text: "b"
        }
        Key {
            key: Qt.Key_N
            text: "n"
        }
        Key {
            key: Qt.Key_M
            text: "m"
        }
        Key {
            key: Qt.Key_Comma
            text: ","
        }
        Key {
            key: Qt.Key_Period
            text: "."
        }
        Key {
            key: Qt.Key_Slash
            text: "/"
        }
        Key {
            key: Qt.Key_Shift
            text: "Shift"
            weight: functionKeyWidth
            functionKey: true
            Layout.fillWidth: false
        }
    }
    KeyboardRow {
        Key {
            key: Qt.Key_Control
            text: "Ctrl"
        }
        Key {
            key: Qt.Key_Alt
            text: "Alt"
        }
        Key {
            key: Qt.Key_Meta
            text: "Meta"
        }
        SpaceKey {
            weight: 700
        }
        Key {
            key: Qt.Key_AltGr
            text: "AltGr"
        }
        Key {
            key: Qt.Key_Menu
            text: "RClick"
        }
        HideKeyboardKey {
            weight: normalKeyWidth
            Layout.fillWidth: false
            // perhaps it would be better if hiding the keyboard then disables it?
            // `org.kde.kwin.virtualkeyboard.enabled` in dbus
        }
        
    }
}
