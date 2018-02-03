/****************************************************************************
** Meta object code from reading C++ file 'addfriend.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "addfriend.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addfriend.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AddFriend_t {
    QByteArrayData data[10];
    char stringdata0[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AddFriend_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AddFriend_t qt_meta_stringdata_AddFriend = {
    {
QT_MOC_LITERAL(0, 0, 9), // "AddFriend"
QT_MOC_LITERAL(1, 10, 9), // "addSignal"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 11), // "std::string"
QT_MOC_LITERAL(4, 33, 13), // "quitAddFriend"
QT_MOC_LITERAL(5, 47, 20), // "on_addFriend_clicked"
QT_MOC_LITERAL(6, 68, 21), // "on_quitButton_clicked"
QT_MOC_LITERAL(7, 90, 10), // "closeEvent"
QT_MOC_LITERAL(8, 101, 12), // "QCloseEvent*"
QT_MOC_LITERAL(9, 114, 5) // "event"

    },
    "AddFriend\0addSignal\0\0std::string\0"
    "quitAddFriend\0on_addFriend_clicked\0"
    "on_quitButton_clicked\0closeEvent\0"
    "QCloseEvent*\0event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddFriend[] = {

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
       1,    1,   39,    2, 0x06 /* Public */,
       4,    0,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   43,    2, 0x08 /* Private */,
       6,    0,   44,    2, 0x08 /* Private */,
       7,    1,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

void AddFriend::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AddFriend *_t = static_cast<AddFriend *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addSignal((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 1: _t->quitAddFriend(); break;
        case 2: _t->on_addFriend_clicked(); break;
        case 3: _t->on_quitButton_clicked(); break;
        case 4: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AddFriend::*_t)(std::string );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AddFriend::addSignal)) {
                *result = 0;
            }
        }
        {
            typedef void (AddFriend::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AddFriend::quitAddFriend)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject AddFriend::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AddFriend.data,
      qt_meta_data_AddFriend,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AddFriend::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddFriend::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AddFriend.stringdata0))
        return static_cast<void*>(const_cast< AddFriend*>(this));
    return QDialog::qt_metacast(_clname);
}

int AddFriend::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void AddFriend::addSignal(std::string _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AddFriend::quitAddFriend()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
