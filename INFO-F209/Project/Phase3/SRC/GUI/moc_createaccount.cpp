/****************************************************************************
** Meta object code from reading C++ file 'createaccount.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "createaccount.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'createaccount.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CreateAccount_t {
    QByteArrayData data[12];
    char stringdata0[158];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreateAccount_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreateAccount_t qt_meta_stringdata_CreateAccount = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CreateAccount"
QT_MOC_LITERAL(1, 14, 12), // "createSignal"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 11), // "std::string"
QT_MOC_LITERAL(4, 40, 8), // "username"
QT_MOC_LITERAL(5, 49, 8), // "password"
QT_MOC_LITERAL(6, 58, 23), // "quitCreateAccountSignal"
QT_MOC_LITERAL(7, 82, 23), // "on_CreateButton_clicked"
QT_MOC_LITERAL(8, 106, 21), // "on_QuitButton_clicked"
QT_MOC_LITERAL(9, 128, 10), // "closeEvent"
QT_MOC_LITERAL(10, 139, 12), // "QCloseEvent*"
QT_MOC_LITERAL(11, 152, 5) // "event"

    },
    "CreateAccount\0createSignal\0\0std::string\0"
    "username\0password\0quitCreateAccountSignal\0"
    "on_CreateButton_clicked\0on_QuitButton_clicked\0"
    "closeEvent\0QCloseEvent*\0event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateAccount[] = {

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

void CreateAccount::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreateAccount *_t = static_cast<CreateAccount *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->createSignal((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->quitCreateAccountSignal(); break;
        case 2: _t->on_CreateButton_clicked(); break;
        case 3: _t->on_QuitButton_clicked(); break;
        case 4: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CreateAccount::*_t)(std::string , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CreateAccount::createSignal)) {
                *result = 0;
            }
        }
        {
            typedef void (CreateAccount::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CreateAccount::quitCreateAccountSignal)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject CreateAccount::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CreateAccount.data,
      qt_meta_data_CreateAccount,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CreateAccount::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateAccount::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CreateAccount.stringdata0))
        return static_cast<void*>(const_cast< CreateAccount*>(this));
    if (!strcmp(_clname, "Ui_CreateAccount"))
        return static_cast< Ui_CreateAccount*>(const_cast< CreateAccount*>(this));
    return QDialog::qt_metacast(_clname);
}

int CreateAccount::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void CreateAccount::createSignal(std::string _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CreateAccount::quitCreateAccountSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
