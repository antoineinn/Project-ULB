/****************************************************************************
** Meta object code from reading C++ file 'menuoption.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "menuoption.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'menuoption.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MenuOption_t {
    QByteArrayData data[18];
    char stringdata0[294];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MenuOption_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MenuOption_t qt_meta_stringdata_MenuOption = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MenuOption"
QT_MOC_LITERAL(1, 11, 10), // "showFriend"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 10), // "showProfil"
QT_MOC_LITERAL(4, 34, 11), // "showRanking"
QT_MOC_LITERAL(5, 46, 12), // "signalLogOut"
QT_MOC_LITERAL(6, 59, 10), // "playSignal"
QT_MOC_LITERAL(7, 70, 27), // "on_showFriendButton_clicked"
QT_MOC_LITERAL(8, 98, 27), // "on_showProfilButton_clicked"
QT_MOC_LITERAL(9, 126, 28), // "on_showRankingButton_clicked"
QT_MOC_LITERAL(10, 155, 22), // "on_leaveButton_clicked"
QT_MOC_LITERAL(11, 178, 10), // "closeEvent"
QT_MOC_LITERAL(12, 189, 12), // "QCloseEvent*"
QT_MOC_LITERAL(13, 202, 5), // "event"
QT_MOC_LITERAL(14, 208, 21), // "on_playButton_clicked"
QT_MOC_LITERAL(15, 230, 19), // "on_vsButton_toggled"
QT_MOC_LITERAL(16, 250, 21), // "on_teamButton_toggled"
QT_MOC_LITERAL(17, 272, 21) // "on_timeButton_toggled"

    },
    "MenuOption\0showFriend\0\0showProfil\0"
    "showRanking\0signalLogOut\0playSignal\0"
    "on_showFriendButton_clicked\0"
    "on_showProfilButton_clicked\0"
    "on_showRankingButton_clicked\0"
    "on_leaveButton_clicked\0closeEvent\0"
    "QCloseEvent*\0event\0on_playButton_clicked\0"
    "on_vsButton_toggled\0on_teamButton_toggled\0"
    "on_timeButton_toggled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MenuOption[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    0,   85,    2, 0x06 /* Public */,
       4,    0,   86,    2, 0x06 /* Public */,
       5,    0,   87,    2, 0x06 /* Public */,
       6,    1,   88,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   91,    2, 0x08 /* Private */,
       8,    0,   92,    2, 0x08 /* Private */,
       9,    0,   93,    2, 0x08 /* Private */,
      10,    0,   94,    2, 0x08 /* Private */,
      11,    1,   95,    2, 0x08 /* Private */,
      14,    0,   98,    2, 0x08 /* Private */,
      15,    0,   99,    2, 0x08 /* Private */,
      16,    0,  100,    2, 0x08 /* Private */,
      17,    0,  101,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MenuOption::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MenuOption *_t = static_cast<MenuOption *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showFriend(); break;
        case 1: _t->showProfil(); break;
        case 2: _t->showRanking(); break;
        case 3: _t->signalLogOut(); break;
        case 4: _t->playSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_showFriendButton_clicked(); break;
        case 6: _t->on_showProfilButton_clicked(); break;
        case 7: _t->on_showRankingButton_clicked(); break;
        case 8: _t->on_leaveButton_clicked(); break;
        case 9: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 10: _t->on_playButton_clicked(); break;
        case 11: _t->on_vsButton_toggled(); break;
        case 12: _t->on_teamButton_toggled(); break;
        case 13: _t->on_timeButton_toggled(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MenuOption::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MenuOption::showFriend)) {
                *result = 0;
            }
        }
        {
            typedef void (MenuOption::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MenuOption::showProfil)) {
                *result = 1;
            }
        }
        {
            typedef void (MenuOption::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MenuOption::showRanking)) {
                *result = 2;
            }
        }
        {
            typedef void (MenuOption::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MenuOption::signalLogOut)) {
                *result = 3;
            }
        }
        {
            typedef void (MenuOption::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MenuOption::playSignal)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject MenuOption::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MenuOption.data,
      qt_meta_data_MenuOption,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MenuOption::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MenuOption::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MenuOption.stringdata0))
        return static_cast<void*>(const_cast< MenuOption*>(this));
    return QDialog::qt_metacast(_clname);
}

int MenuOption::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void MenuOption::showFriend()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MenuOption::showProfil()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void MenuOption::showRanking()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void MenuOption::signalLogOut()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void MenuOption::playSignal(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
