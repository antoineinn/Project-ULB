/****************************************************************************
** Meta object code from reading C++ file 'menu_gui.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../menu_gui.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'menu_gui.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MenuGui_t {
    QByteArrayData data[17];
    char stringdata0[228];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MenuGui_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MenuGui_t qt_meta_stringdata_MenuGui = {
    {
QT_MOC_LITERAL(0, 0, 7), // "MenuGui"
QT_MOC_LITERAL(1, 8, 18), // "displayPlayerLogIn"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 20), // "displayCreateAccount"
QT_MOC_LITERAL(4, 49, 10), // "startParty"
QT_MOC_LITERAL(5, 60, 10), // "friendView"
QT_MOC_LITERAL(6, 71, 13), // "displayProfil"
QT_MOC_LITERAL(7, 85, 14), // "displayRanking"
QT_MOC_LITERAL(8, 100, 11), // "playerLogIn"
QT_MOC_LITERAL(9, 112, 11), // "std::string"
QT_MOC_LITERAL(10, 124, 15), // "registerAccount"
QT_MOC_LITERAL(11, 140, 19), // "displayPlayerOption"
QT_MOC_LITERAL(12, 160, 13), // "quitLogInMenu"
QT_MOC_LITERAL(13, 174, 21), // "quitCreateAccountMenu"
QT_MOC_LITERAL(14, 196, 6), // "logOut"
QT_MOC_LITERAL(15, 203, 15), // "exitApplication"
QT_MOC_LITERAL(16, 219, 8) // "quitGame"

    },
    "MenuGui\0displayPlayerLogIn\0\0"
    "displayCreateAccount\0startParty\0"
    "friendView\0displayProfil\0displayRanking\0"
    "playerLogIn\0std::string\0registerAccount\0"
    "displayPlayerOption\0quitLogInMenu\0"
    "quitCreateAccountMenu\0logOut\0"
    "exitApplication\0quitGame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MenuGui[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    1,   86,    2, 0x08 /* Private */,
       5,    0,   89,    2, 0x08 /* Private */,
       6,    0,   90,    2, 0x08 /* Private */,
       7,    0,   91,    2, 0x08 /* Private */,
       8,    2,   92,    2, 0x08 /* Private */,
      10,    2,   97,    2, 0x08 /* Private */,
      11,    0,  102,    2, 0x08 /* Private */,
      12,    0,  103,    2, 0x08 /* Private */,
      13,    0,  104,    2, 0x08 /* Private */,
      14,    0,  105,    2, 0x08 /* Private */,
      15,    0,  106,    2, 0x08 /* Private */,
      16,    0,  107,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9, QMetaType::Int,    2,    2,
    QMetaType::Void, 0x80000000 | 9, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MenuGui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MenuGui *_t = static_cast<MenuGui *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->displayPlayerLogIn(); break;
        case 1: _t->displayCreateAccount(); break;
        case 2: _t->startParty((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->friendView(); break;
        case 4: _t->displayProfil(); break;
        case 5: _t->displayRanking(); break;
        case 6: _t->playerLogIn((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->registerAccount((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->displayPlayerOption(); break;
        case 9: _t->quitLogInMenu(); break;
        case 10: _t->quitCreateAccountMenu(); break;
        case 11: _t->logOut(); break;
        case 12: _t->exitApplication(); break;
        case 13: _t->quitGame(); break;
        default: ;
        }
    }
}

const QMetaObject MenuGui::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MenuGui.data,
      qt_meta_data_MenuGui,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MenuGui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MenuGui::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MenuGui.stringdata0))
        return static_cast<void*>(const_cast< MenuGui*>(this));
    return QObject::qt_metacast(_clname);
}

int MenuGui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
