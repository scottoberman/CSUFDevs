/****************************************************************************
** Meta object code from reading C++ file 'p3mod.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../p3mod.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'p3mod.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_P3mod_t {
    QByteArrayData data[9];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_P3mod_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_P3mod_t qt_meta_stringdata_P3mod = {
    {
QT_MOC_LITERAL(0, 0, 5), // "P3mod"
QT_MOC_LITERAL(1, 6, 16), // "ReturnToItemMain"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 10), // "changeMade"
QT_MOC_LITERAL(4, 35, 14), // "AddItemClicked"
QT_MOC_LITERAL(5, 50, 25), // "ModifySelectedItemClicked"
QT_MOC_LITERAL(6, 76, 15), // "QModelIndexList"
QT_MOC_LITERAL(7, 92, 19), // "CancelButtonPressed"
QT_MOC_LITERAL(8, 112, 19) // "SubmitButtonPressed"

    },
    "P3mod\0ReturnToItemMain\0\0changeMade\0"
    "AddItemClicked\0ModifySelectedItemClicked\0"
    "QModelIndexList\0CancelButtonPressed\0"
    "SubmitButtonPressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_P3mod[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   42,    2, 0x0a /* Public */,
       5,    1,   43,    2, 0x0a /* Public */,
       7,    0,   46,    2, 0x0a /* Public */,
       8,    0,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void P3mod::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        P3mod *_t = static_cast<P3mod *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ReturnToItemMain((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->AddItemClicked(); break;
        case 2: _t->ModifySelectedItemClicked((*reinterpret_cast< QModelIndexList(*)>(_a[1]))); break;
        case 3: _t->CancelButtonPressed(); break;
        case 4: _t->SubmitButtonPressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
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
            typedef void (P3mod::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&P3mod::ReturnToItemMain)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject P3mod::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_P3mod.data,
      qt_meta_data_P3mod,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *P3mod::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *P3mod::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_P3mod.stringdata0))
        return static_cast<void*>(const_cast< P3mod*>(this));
    return QWidget::qt_metacast(_clname);
}

int P3mod::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void P3mod::ReturnToItemMain(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
