/****************************************************************************
** Meta object code from reading C++ file 'spielbrett.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Minesweeper/spielbrett.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'spielbrett.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Spielbrett_t {
    QByteArrayData data[10];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Spielbrett_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Spielbrett_t qt_meta_stringdata_Spielbrett = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Spielbrett"
QT_MOC_LITERAL(1, 11, 13), // "initialisiert"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 6), // "klickt"
QT_MOC_LITERAL(4, 33, 4), // "sieg"
QT_MOC_LITERAL(5, 38, 8), // "verloren"
QT_MOC_LITERAL(6, 47, 14), // "timer_anhalten"
QT_MOC_LITERAL(7, 62, 8), // "geklickt"
QT_MOC_LITERAL(8, 71, 15), // "minen_verteilen"
QT_MOC_LITERAL(9, 87, 14) // "alle_aufdecken"

    },
    "Spielbrett\0initialisiert\0\0klickt\0sieg\0"
    "verloren\0timer_anhalten\0geklickt\0"
    "minen_verteilen\0alle_aufdecken"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Spielbrett[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,
       5,    0,   57,    2, 0x06 /* Public */,
       6,    0,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   59,    2, 0x0a /* Public */,
       8,    0,   60,    2, 0x0a /* Public */,
       9,    0,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Spielbrett::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Spielbrett *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->initialisiert(); break;
        case 1: _t->klickt(); break;
        case 2: _t->sieg(); break;
        case 3: _t->verloren(); break;
        case 4: _t->timer_anhalten(); break;
        case 5: _t->geklickt(); break;
        case 6: _t->minen_verteilen(); break;
        case 7: _t->alle_aufdecken(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Spielbrett::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Spielbrett::initialisiert)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Spielbrett::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Spielbrett::klickt)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Spielbrett::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Spielbrett::sieg)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Spielbrett::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Spielbrett::verloren)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Spielbrett::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Spielbrett::timer_anhalten)) {
                *result = 4;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Spielbrett::staticMetaObject = { {
    &QFrame::staticMetaObject,
    qt_meta_stringdata_Spielbrett.data,
    qt_meta_data_Spielbrett,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Spielbrett::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Spielbrett::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Spielbrett.stringdata0))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int Spielbrett::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
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
void Spielbrett::initialisiert()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Spielbrett::klickt()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Spielbrett::sieg()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Spielbrett::verloren()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Spielbrett::timer_anhalten()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
