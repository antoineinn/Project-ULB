/****************************************************************************
** Meta object code from reading C++ file 'friend_menu_gui.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../friend_menu_gui.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'friend_menu_gui.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FriendGui_t {
    QByteArrayData data[13];
    char stringdata0[193];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FriendGui_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FriendGui_t qt_meta_stringdata_FriendGui = {
    {
QT_MOC_LITERAL(0, 0, 9), // "FriendGui"
QT_MOC_LITERAL(1, 10, 16), // "returnMenuOption"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 20), // "displayAddFriendMenu"
QT_MOC_LITERAL(4, 49, 23), // "displayDeleteFriendMenu"
QT_MOC_LITERAL(5, 73, 18), // "displayRequestMenu"
QT_MOC_LITERAL(6, 92, 17), // "displayFriendList"
QT_MOC_LITERAL(7, 110, 9), // "addFriend"
QT_MOC_LITERAL(8, 120, 11), // "std::string"
QT_MOC_LITERAL(9, 132, 12), // "deleteFriend"
QT_MOC_LITERAL(10, 145, 17), // "quitAddFriendMenu"
QT_MOC_LITERAL(11, 163, 20), // "quitDeleteFriendMenu"
QT_MOC_LITERAL(12, 184, 8) // "exitMenu"

    },
    "FriendGui\0returnMenuOption\0\0"
    "displayAddFriendMenu\0displayDeleteFriendMenu\0"
    "displayRequestMenu\0displayFriendList\0"
    "addFriend\0std::string\0deleteFriend\0"
    "quitAddFriendMenu\0quitDeleteFriendMenu\0"
    "exitMenu"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FriendGui[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    1,   69,    2, 0x08 /* Private */,
       9,    1,   72,    2, 0x08 /* Private */,
      10,    0,   75,    2, 0x08 /* Private */,
      11,    0,   76,    2, 0x08 /* Private */,
      12,    0,   77,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FriendGui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FriendGui *_t = static_cast<FriendGui *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->returnMenuOption(); break;
        case 1: _t->displayAddFriendMenu(); break;
        case 2: _t->displayDeleteFriendMenu(); break;
        case 3: _t->displayRequestMenu(); break;
        case 4: _t->displayFriendList(); break;
        case 5: _t->addFriend((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 6: _t->deleteFriend((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 7: _t->quitAddFriendMenu(); break;
        case 8: _t->quitDeleteFriendMenu(); break;
        case 9: _t->exitMenu(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FriendGui::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FriendGui::returnMenuOption)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject FriendGui::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FriendGui.data,
      qt_meta_data_FriendGui,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FriendGui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FriendGui::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FriendGui.stringdata0))
        return static_cast<void*>(const_cast< FriendGui*>(this));
    return QObject::qt_metacast(_clname);
}

int FriendGui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void FriendGui::returnMenuOption()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
