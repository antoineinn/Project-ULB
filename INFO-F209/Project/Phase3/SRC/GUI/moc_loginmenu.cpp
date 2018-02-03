/****************************************************************************
** Meta object code from reading C++ file 'loginmenu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "loginmenu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loginmenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LoginMenu_t {
    QByteArrayData data[12];
    char stringdata0[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LoginMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LoginMenu_t qt_meta_stringdata_LoginMenu = {
    {
QT_MOC_LITERAL(0, 0, 9), // "LoginMenu"
QT_MOC_LITERAL(1, 10, 11), // "loginSignal"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 11), // "std::string"
QT_MOC_LITERAL(4, 35, 8), // "username"
QT_MOC_LITERAL(5, 44, 8), // "password"
QT_MOC_LITERAL(6, 53, 15), // "quitLogInSignal"
QT_MOC_LITERAL(7, 69, 22), // "on_LoginButton_clicked"
QT_MOC_LITERAL(8, 92, 21), // "on_QuitButton_clicked"
QT_MOC_LITERAL(9, 114, 10), // "closeEvent"
QT_MOC_LITERAL(10, 125, 12), // "QCloseEvent*"
QT_MOC_LITERAL(11, 138, 5) // "event"

    },
    "LoginMenu\0loginSignal\0\0std::string\0"
    "username\0password\0quitLogInSignal\0"
    "on_LoginButton_clicked\0on_QuitButton_clicked\0"
    "closeEvent\0QCloseEvent*\0event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LoginMenu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,
       6,    0,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   45,    2, 0x08 /* Private */,
       8,    0,   46,    2, 0x08 /* Private */,
       9,    1,   47,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,

       0        // eod
};

void LoginMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LoginMenu *_t = static_cast<LoginMenu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loginSignal((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->quitLogInSignal(); break;
        case 2: _t->on_LoginButton_clicked(); break;
        case 3: _t->on_QuitButton_clicked(); break;
        case 4: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LoginMenu::*_t)(std::string , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoginMenu::loginSignal)) {
                *result = 0;
            }
        }
        {
            typedef void (LoginMenu::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoginMenu::quitLogInSignal)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject LoginMenu::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_LoginMenu.data,
      qt_meta_data_LoginMenu,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LoginMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LoginMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LoginMenu.stringdata0))
        return static_cast<void*>(const_cast< LoginMenu*>(this));
    return QDialog::qt_metacast(_clname);
}

int LoginMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void LoginMenu::loginSignal(std::string _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LoginMenu::quitLogInSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
