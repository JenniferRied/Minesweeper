#ifndef KACHEL_H
#define KACHEL_H



class Kachel
{
public:
    Kachel();

    bool ist_mine();
    bool ist_markiert();
    bool ist_aufgedeckt();
    bool hat_benachbarte_minen();

};

#endif // KACHEL_H
