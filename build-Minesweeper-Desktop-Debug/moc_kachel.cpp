/****************************************************************************
** Meta object code from reading C++ file 'kachel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Minesweeper/kachel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kachel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Kachel_t {
    QByteArrayData data[21];
    char stringdata0[266];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Kachel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Kachel_t qt_meta_stringdata_Kachel = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Kachel"
QT_MOC_LITERAL(1, 7, 10), // "firstClick"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 7), // "Kachel*"
QT_MOC_LITERAL(4, 27, 11), // "leftClicked"
QT_MOC_LITERAL(5, 39, 12), // "rightClicked"
QT_MOC_LITERAL(6, 52, 11), // "bothClicked"
QT_MOC_LITERAL(7, 64, 9), // "unClicked"
QT_MOC_LITERAL(8, 74, 9), // "detonated"
QT_MOC_LITERAL(9, 84, 6), // "reveal"
QT_MOC_LITERAL(10, 91, 8), // "revealed"
QT_MOC_LITERAL(11, 100, 15), // "revealNeighbors"
QT_MOC_LITERAL(12, 116, 7), // "preview"
QT_MOC_LITERAL(13, 124, 9), // "unPreview"
QT_MOC_LITERAL(14, 134, 18), // "unPreviewNeighbors"
QT_MOC_LITERAL(15, 153, 7), // "flagged"
QT_MOC_LITERAL(16, 161, 9), // "unFlagged"
QT_MOC_LITERAL(17, 171, 7), // "disable"
QT_MOC_LITERAL(18, 179, 29), // "incrementAdjacentFlaggedCount"
QT_MOC_LITERAL(19, 209, 29), // "decrementAdjacentFlaggedCount"
QT_MOC_LITERAL(20, 239, 26) // "incrementAdjacentMineCount"

    },
    "Kachel\0firstClick\0\0Kachel*\0leftClicked\0"
    "rightClicked\0bothClicked\0unClicked\0"
    "detonated\0reveal\0revealed\0revealNeighbors\0"
    "preview\0unPreview\0unPreviewNeighbors\0"
    "flagged\0unFlagged\0disable\0"
    "incrementAdjacentFlaggedCount\0"
    "decrementAdjacentFlaggedCount\0"
    "incrementAdjacentMineCount"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Kachel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      15,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  104,    2, 0x06 /* Public */,
       4,    0,  107,    2, 0x06 /* Public */,
       5,    0,  108,    2, 0x06 /* Public */,
       6,    0,  109,    2, 0x06 /* Public */,
       7,    0,  110,    2, 0x06 /* Public */,
       8,    0,  111,    2, 0x06 /* Public */,
       9,    0,  112,    2, 0x06 /* Public */,
      10,    0,  113,    2, 0x06 /* Public */,
      11,    0,  114,    2, 0x06 /* Public */,
      12,    0,  115,    2, 0x06 /* Public */,
      13,    0,  116,    2, 0x06 /* Public */,
      14,    0,  117,    2, 0x06 /* Public */,
      15,    1,  118,    2, 0x06 /* Public */,
      16,    1,  121,    2, 0x06 /* Public */,
      17,    0,  124,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    0,  125,    2, 0x0a /* Public */,
      19,    0,  126,    2, 0x0a /* Public */,
      20,    0,  127,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Kachel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Kachel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->firstClick((*reinterpret_cast< Kachel*(*)>(_a[1]))); break;
        case 1: _t->leftClicked(); break;
        case 2: _t->rightClicked(); break;
        case 3: _t->bothClicked(); break;
        case 4: _t->unClicked(); break;
        case 5: _t->detonated(); break;
        case 6: _t->reveal(); break;
        case 7: _t->revealed(); break;
        case 8: _t->revealNeighbors(); break;
        case 9: _t->preview(); break;
        case 10: _t->unPreview(); break;
        case 11: _t->unPreviewNeighbors(); break;
        case 12: _t->flagged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->unFlagged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->disable(); break;
        case 15: _t->incrementAdjacentFlaggedCount(); break;
        case 16: _t->decrementAdjacentFlaggedCount(); break;
        case 17: _t->incrementAdjacentMineCount(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Kachel* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Kachel::*)(Kachel * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Kachel::firstClick)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Kachel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Kachel::leftClicked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Kachel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Kachel::rightClicked)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Kachel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Kachel::bothClicked)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Kachel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Kachel::unClicked)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Kachel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Kachel::detonated)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Kachel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Kachel::reveal)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Kachel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Kachel::revealed)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Kachel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Kachel::revealNeighbors)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Kachel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Kachel::preview)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (Kachel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Kachel::unPreview)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (Kachel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Kachel::unPreviewNeighbors)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (Kachel::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Kachel::flagged)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (Kachel::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Kachel::unFlagged)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (Kachel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Kachel::disable)) {
                *result = 14;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Kachel::staticMetaObject = { {
    &QPushButton::staticMetaObject,
    qt_meta_stringdata_Kachel.data,
    qt_meta_data_Kachel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Kachel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Kachel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Kachel.stringdata0))
        return static_cast<void*>(this);
    return QPushButton::qt_metacast(_clname);
}

int Kachel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void Kachel::firstClick(Kachel * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Kachel::leftClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Kachel::rightClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Kachel::bothClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Kachel::unClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Kachel::detonated()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Kachel::reveal()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Kachel::revealed()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void Kachel::revealNeighbors()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void Kachel::preview()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void Kachel::unPreview()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void Kachel::unPreviewNeighbors()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void Kachel::flagged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void Kachel::unFlagged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void Kachel::disable()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
