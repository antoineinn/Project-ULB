/****************************************************************************
** Meta object code from reading C++ file 'friendmenu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "friendmenu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'friendmenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FriendMenu_t {
    QByteArrayData data[15];
    char stringdata0[241];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FriendMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FriendMenu_t qt_meta_stringdata_FriendMenu = {
    {
QT_MOC_LITERAL(0, 0, 10), // "FriendMenu"
QT_MOC_LITERAL(1, 11, 10), // "signalQuit"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 13), // "showAddFriend"
QT_MOC_LITERAL(4, 37, 16), // "showDeleteFriend"
QT_MOC_LITERAL(5, 54, 17), // "showRequestFriend"
QT_MOC_LITERAL(6, 72, 14), // "showFriendList"
QT_MOC_LITERAL(7, 87, 21), // "on_QuitButton_clicked"
QT_MOC_LITERAL(8, 109, 20), // "on_AddButton_clicked"
QT_MOC_LITERAL(9, 130, 23), // "on_DeleteButton_clicked"
QT_MOC_LITERAL(10, 154, 28), // "on_showRequestButton_clicked"
QT_MOC_LITERAL(11, 183, 27), // "on_showFriendButton_clicked"
QT_MOC_LITERAL(12, 211, 10), // "closeEvent"
QT_MOC_LITERAL(13, 222, 12), // "QCloseEvent*"
QT_MOC_LITERAL(14, 235, 5) // "event"

    },
    "FriendMenu\0signalQuit\0\0showAddFriend\0"
    "showDeleteFriend\0showRequestFriend\0"
    "showFriendList\0on_QuitButton_clicked\0"
    "on_AddButton_clicked\0on_DeleteButton_clicked\0"
    "on_showRequestButton_clicked\0"
    "on_showFriendButton_clicked\0closeEvent\0"
    "QCloseEvent*\0event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FriendMenu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,
       4,    0,   71,    2, 0x06 /* Public */,
       5,    0,   72,    2, 0x06 /* Public */,
       6,    0,   73,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    1,   79,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,

       0        // eod
};

void FriendMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FriendMenu *_t = static_cast<FriendMenu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalQuit(); break;
        case 1: _t->showAddFriend(); break;
        case 2: _t->showDeleteFriend(); break;
        case 3: _t->showRequestFriend(); break;
        case 4: _t->showFriendList(); break;
        case 5: _t->on_QuitButton_clicked(); break;
        case 6: _t->on_AddButton_clicked(); break;
        case 7: _t->on_DeleteButton_clicked(); break;
        case 8: _t->on_showRequestButton_clicked(); break;
        case 9: _t->on_showFriendButton_clicked(); break;
        case 10: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FriendMenu::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FriendMenu::signalQuit)) {
                *result = 0;
            }
        }
        {
            typedef void (FriendMenu::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FriendMenu::showAddFriend)) {
                *result = 1;
            }
        }
        {
            typedef void (FriendMenu::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FriendMenu::showDeleteFriend)) {
                *result = 2;
            }
        }
        {
            typedef void (FriendMenu::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FriendMenu::showRequestFriend)) {
                *result = 3;
            }
        }
        {
            typedef void (FriendMenu::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FriendMenu::showFriendList)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject FriendMenu::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_FriendMenu.data,
      qt_meta_data_FriendMenu,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FriendMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FriendMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FriendMenu.stringdata0))
        return static_cast<void*>(const_cast< FriendMenu*>(this));
    return QDialog::qt_metacast(_clname);
}

int FriendMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void FriendMenu::signalQuit()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void FriendMenu::showAddFriend()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void FriendMenu::showDeleteFriend()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void FriendMenu::showRequestFriend()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void FriendMenu::showFriendList()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
