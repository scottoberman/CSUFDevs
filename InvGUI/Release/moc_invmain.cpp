/****************************************************************************
** Meta object code from reading C++ file 'invmain.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../invmain.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'invmain.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_InvMain_t {
    QByteArrayData data[10];
    char stringdata0[135];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_InvMain_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_InvMain_t qt_meta_stringdata_InvMain = {
    {
QT_MOC_LITERAL(0, 0, 7), // "InvMain"
QT_MOC_LITERAL(1, 8, 13), // "LogoutPressed"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 18), // "ModifySelectedItem"
QT_MOC_LITERAL(4, 42, 15), // "QModelIndexList"
QT_MOC_LITERAL(5, 58, 16), // "LoadItemMainPage"
QT_MOC_LITERAL(6, 75, 10), // "changeMade"
QT_MOC_LITERAL(7, 86, 4), // "Exit"
QT_MOC_LITERAL(8, 91, 17), // "on_Logout_clicked"
QT_MOC_LITERAL(9, 109, 25) // "ModifySelectedItemClicked"

    },
    "InvMain\0LogoutPressed\0\0ModifySelectedItem\0"
    "QModelIndexList\0LoadItemMainPage\0"
    "changeMade\0Exit\0on_Logout_clicked\0"
    "ModifySelectedItemClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InvMain[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    1,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   48,    2, 0x0a /* Public */,
       7,    0,   51,    2, 0x0a /* Public */,
       8,    0,   52,    2, 0x08 /* Private */,
       9,    1,   53,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,

       0        // eod
};

void InvMain::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        InvMain *_t = static_cast<InvMain *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->LogoutPressed(); break;
        case 1: _t->ModifySelectedItem((*reinterpret_cast< QModelIndexList(*)>(_a[1]))); break;
        case 2: _t->LoadItemMainPage((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->Exit(); break;
        case 4: _t->on_Logout_clicked(); break;
        case 5: _t->ModifySelectedItemClicked((*reinterpret_cast< QModelIndexList(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QModelIndexList >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QModelIndexList >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (InvMain::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&InvMain::LogoutPressed)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (InvMain::*_t)(QModelIndexList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&InvMain::ModifySelectedItem)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject InvMain::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_InvMain.data,
      qt_meta_data_InvMain,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *InvMain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InvMain::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_InvMain.stringdata0))
        return static_cast<void*>(const_cast< InvMain*>(this));
    return QWidget::qt_metacast(_clname);
}

int InvMain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void InvMain::LogoutPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void InvMain::ModifySelectedItem(QModelIndexList _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
