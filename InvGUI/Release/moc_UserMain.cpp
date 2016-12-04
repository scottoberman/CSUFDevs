/****************************************************************************
** Meta object code from reading C++ file 'UserMain.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../UserMain.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UserMain.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UserMain_t {
    QByteArrayData data[13];
    char stringdata0[206];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UserMain_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UserMain_t qt_meta_stringdata_UserMain = {
    {
QT_MOC_LITERAL(0, 0, 8), // "UserMain"
QT_MOC_LITERAL(1, 9, 30), // "ChangePageToDeleteSelectedUser"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 2), // "ID"
QT_MOC_LITERAL(4, 44, 30), // "ChangePageToModifySelectedUser"
QT_MOC_LITERAL(5, 75, 15), // "QModelIndexList"
QT_MOC_LITERAL(6, 91, 3), // "row"
QT_MOC_LITERAL(7, 95, 10), // "ResetTable"
QT_MOC_LITERAL(8, 106, 11), // "CellClicked"
QT_MOC_LITERAL(9, 118, 12), // "LoadUserMain"
QT_MOC_LITERAL(10, 131, 10), // "changeMade"
QT_MOC_LITERAL(11, 142, 31), // "DeleteSelectedUserButtonClicked"
QT_MOC_LITERAL(12, 174, 31) // "ModifySelectedUserButtonClicked"

    },
    "UserMain\0ChangePageToDeleteSelectedUser\0"
    "\0ID\0ChangePageToModifySelectedUser\0"
    "QModelIndexList\0row\0ResetTable\0"
    "CellClicked\0LoadUserMain\0changeMade\0"
    "DeleteSelectedUserButtonClicked\0"
    "ModifySelectedUserButtonClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserMain[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   55,    2, 0x08 /* Private */,
       8,    0,   56,    2, 0x08 /* Private */,
       9,    1,   57,    2, 0x08 /* Private */,
      11,    0,   60,    2, 0x08 /* Private */,
      12,    0,   61,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 5,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void UserMain::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UserMain *_t = static_cast<UserMain *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ChangePageToDeleteSelectedUser((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 1: _t->ChangePageToModifySelectedUser((*reinterpret_cast< QModelIndexList(*)>(_a[1]))); break;
        case 2: _t->ResetTable(); break;
        case 3: _t->CellClicked(); break;
        case 4: _t->LoadUserMain((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->DeleteSelectedUserButtonClicked(); break;
        case 6: _t->ModifySelectedUserButtonClicked(); break;
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
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (UserMain::*_t)(const int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UserMain::ChangePageToDeleteSelectedUser)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (UserMain::*_t)(QModelIndexList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UserMain::ChangePageToModifySelectedUser)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject UserMain::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_UserMain.data,
      qt_meta_data_UserMain,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UserMain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserMain::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UserMain.stringdata0))
        return static_cast<void*>(const_cast< UserMain*>(this));
    return QWidget::qt_metacast(_clname);
}

int UserMain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void UserMain::ChangePageToDeleteSelectedUser(const int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UserMain::ChangePageToModifySelectedUser(QModelIndexList _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
