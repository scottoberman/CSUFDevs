/****************************************************************************
** Meta object code from reading C++ file 'ItemMain.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ItemMain.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ItemMain.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ItemMain_t {
    QByteArrayData data[10];
    char stringdata0[217];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ItemMain_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ItemMain_t qt_meta_stringdata_ItemMain = {
    {
QT_MOC_LITERAL(0, 0, 8), // "ItemMain"
QT_MOC_LITERAL(1, 9, 19), // "ChangePageToAddItem"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 30), // "ChangePageToModifySelectedItem"
QT_MOC_LITERAL(4, 61, 15), // "QModelIndexList"
QT_MOC_LITERAL(5, 77, 30), // "ChangePageToDeleteSelectedItem"
QT_MOC_LITERAL(6, 108, 24), // "on_AddItemButton_clicked"
QT_MOC_LITERAL(7, 133, 35), // "on_ModifySelectedItemButton_c..."
QT_MOC_LITERAL(8, 169, 35), // "on_DeleteSelectedItemButton_c..."
QT_MOC_LITERAL(9, 205, 11) // "cellClicked"

    },
    "ItemMain\0ChangePageToAddItem\0\0"
    "ChangePageToModifySelectedItem\0"
    "QModelIndexList\0ChangePageToDeleteSelectedItem\0"
    "on_AddItemButton_clicked\0"
    "on_ModifySelectedItemButton_clicked\0"
    "on_DeleteSelectedItemButton_clicked\0"
    "cellClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ItemMain[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    1,   50,    2, 0x06 /* Public */,
       5,    0,   53,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   54,    2, 0x08 /* Private */,
       7,    0,   55,    2, 0x08 /* Private */,
       8,    0,   56,    2, 0x08 /* Private */,
       9,    0,   57,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ItemMain::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ItemMain *_t = static_cast<ItemMain *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ChangePageToAddItem(); break;
        case 1: _t->ChangePageToModifySelectedItem((*reinterpret_cast< QModelIndexList(*)>(_a[1]))); break;
        case 2: _t->ChangePageToDeleteSelectedItem(); break;
        case 3: _t->on_AddItemButton_clicked(); break;
        case 4: _t->on_ModifySelectedItemButton_clicked(); break;
        case 5: _t->on_DeleteSelectedItemButton_clicked(); break;
        case 6: _t->cellClicked(); break;
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
            typedef void (ItemMain::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ItemMain::ChangePageToAddItem)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ItemMain::*_t)(QModelIndexList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ItemMain::ChangePageToModifySelectedItem)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ItemMain::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ItemMain::ChangePageToDeleteSelectedItem)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject ItemMain::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ItemMain.data,
      qt_meta_data_ItemMain,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ItemMain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ItemMain::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ItemMain.stringdata0))
        return static_cast<void*>(const_cast< ItemMain*>(this));
    return QWidget::qt_metacast(_clname);
}

int ItemMain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ItemMain::ChangePageToAddItem()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void ItemMain::ChangePageToModifySelectedItem(QModelIndexList _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ItemMain::ChangePageToDeleteSelectedItem()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
