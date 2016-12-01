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
    QByteArrayData data[11];
    char stringdata0[178];
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
QT_MOC_LITERAL(3, 23, 8), // "GoToPage"
QT_MOC_LITERAL(4, 32, 12), // "newPageIndex"
QT_MOC_LITERAL(5, 45, 22), // "on_Page1Button_clicked"
QT_MOC_LITERAL(6, 68, 22), // "on_Page2Button_clicked"
QT_MOC_LITERAL(7, 91, 22), // "on_Page3Button_clicked"
QT_MOC_LITERAL(8, 114, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(9, 136, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(10, 160, 17) // "on_Logout_clicked"

    },
    "InvMain\0LogoutPressed\0\0GoToPage\0"
    "newPageIndex\0on_Page1Button_clicked\0"
    "on_Page2Button_clicked\0on_Page3Button_clicked\0"
    "on_pushButton_clicked\0on_pushButton_2_clicked\0"
    "on_Logout_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InvMain[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   55,    2, 0x0a /* Public */,
       5,    0,   58,    2, 0x08 /* Private */,
       6,    0,   59,    2, 0x08 /* Private */,
       7,    0,   60,    2, 0x08 /* Private */,
       8,    0,   61,    2, 0x08 /* Private */,
       9,    0,   62,    2, 0x08 /* Private */,
      10,    0,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void InvMain::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        InvMain *_t = static_cast<InvMain *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->LogoutPressed(); break;
        case 1: _t->GoToPage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_Page1Button_clicked(); break;
        case 3: _t->on_Page2Button_clicked(); break;
        case 4: _t->on_Page3Button_clicked(); break;
        case 5: _t->on_pushButton_clicked(); break;
        case 6: _t->on_pushButton_2_clicked(); break;
        case 7: _t->on_Logout_clicked(); break;
        default: ;
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
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void InvMain::LogoutPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
