/****************************************************************************
** Meta object code from reading C++ file 'deletefriend.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "deletefriend.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'deletefriend.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DeleteFriend_t {
    QByteArrayData data[10];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DeleteFriend_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DeleteFriend_t qt_meta_stringdata_DeleteFriend = {
    {
QT_MOC_LITERAL(0, 0, 12), // "DeleteFriend"
QT_MOC_LITERAL(1, 13, 12), // "deleteSignal"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 11), // "std::string"
QT_MOC_LITERAL(4, 39, 16), // "quitDeleteFriend"
QT_MOC_LITERAL(5, 56, 23), // "on_deleteFriend_clicked"
QT_MOC_LITERAL(6, 80, 21), // "on_quitButton_clicked"
QT_MOC_LITERAL(7, 102, 10), // "closeEvent"
QT_MOC_LITERAL(8, 113, 12), // "QCloseEvent*"
QT_MOC_LITERAL(9, 126, 5) // "event"

    },
    "DeleteFriend\0deleteSignal\0\0std::string\0"
    "quitDeleteFriend\0on_deleteFriend_clicked\0"
    "on_quitButton_clicked\0closeEvent\0"
    "QCloseEvent*\0event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DeleteFriend[] = {

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

void DeleteFriend::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DeleteFriend *_t = static_cast<DeleteFriend *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->deleteSignal((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 1: _t->quitDeleteFriend(); break;
        case 2: _t->on_deleteFriend_clicked(); break;
        case 3: _t->on_quitButton_clicked(); break;
        case 4: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DeleteFriend::*_t)(std::string );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DeleteFriend::deleteSignal)) {
                *result = 0;
            }
        }
        {
            typedef void (DeleteFriend::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DeleteFriend::quitDeleteFriend)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject DeleteFriend::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DeleteFriend.data,
      qt_meta_data_DeleteFriend,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DeleteFriend::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DeleteFriend::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DeleteFriend.stringdata0))
        return static_cast<void*>(const_cast< DeleteFriend*>(this));
    return QDialog::qt_metacast(_clname);
}

int DeleteFriend::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void DeleteFriend::deleteSignal(std::string _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DeleteFriend::quitDeleteFriend()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
