/****************************************************************************
** Meta object code from reading C++ file 'gamedisplaygui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "gamedisplaygui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamedisplaygui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GameDisplayGui_t {
    QByteArrayData data[6];
    char stringdata0[61];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameDisplayGui_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameDisplayGui_t qt_meta_stringdata_GameDisplayGui = {
    {
QT_MOC_LITERAL(0, 0, 14), // "GameDisplayGui"
QT_MOC_LITERAL(1, 15, 14), // "quitSignalGame"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 10), // "closeEvent"
QT_MOC_LITERAL(4, 42, 12), // "QCloseEvent*"
QT_MOC_LITERAL(5, 55, 5) // "event"

    },
    "GameDisplayGui\0quitSignalGame\0\0"
    "closeEvent\0QCloseEvent*\0event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameDisplayGui[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   25,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,

       0        // eod
};

void GameDisplayGui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GameDisplayGui *_t = static_cast<GameDisplayGui *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->quitSignalGame(); break;
        case 1: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GameDisplayGui::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameDisplayGui::quitSignalGame)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject GameDisplayGui::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GameDisplayGui.data,
      qt_meta_data_GameDisplayGui,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GameDisplayGui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameDisplayGui::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GameDisplayGui.stringdata0))
        return static_cast<void*>(const_cast< GameDisplayGui*>(this));
    return QWidget::qt_metacast(_clname);
}

int GameDisplayGui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void GameDisplayGui::quitSignalGame()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
