/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
* This program is free software licensed under GPL version 2
* Please see the included DOCS/LICENSE.TXT for more information */

#ifndef SC_SYSTEM_H
#define SC_SYSTEM_H

#include "ScriptMgr.h"

#define TEXT_SOURCE_RANGE -1000000                          //the amount of entries each text source has available

//TODO: find better namings and definitions.
//N=Neutral, A=Alliance, H=Horde.
//NEUTRAL or FRIEND = Hostility to player surroundings (not a good definition)
//ACTIVE or PASSIVE = Hostility to environment surroundings.
enum eEscortFaction
{
    FACTION_ESCORT_A_NEUTRAL_PASSIVE    = 10,
    FACTION_ESCORT_H_NEUTRAL_PASSIVE    = 33,
    FACTION_ESCORT_N_NEUTRAL_PASSIVE    = 113,

    FACTION_ESCORT_A_NEUTRAL_ACTIVE     = 231,
    FACTION_ESCORT_H_NEUTRAL_ACTIVE     = 232,
    FACTION_ESCORT_N_NEUTRAL_ACTIVE     = 250,

    FACTION_ESCORT_N_FRIEND_PASSIVE     = 290,
    FACTION_ESCORT_N_FRIEND_ACTIVE      = 495,

    FACTION_ESCORT_A_PASSIVE            = 774,
    FACTION_ESCORT_H_PASSIVE            = 775,

    FACTION_ESCORT_N_ACTIVE             = 1986,
    FACTION_ESCORT_H_ACTIVE             = 2046
};

struct ScriptPointMove
{
    uint32 uiCreatureEntry;
    uint32 uiPointId;
    float  fX;
    float  fY;
    float  fZ;
    uint32 uiWaitTime;
};

typedef std::vector<ScriptPointMove> ScriptPointVector;

struct StringTextData
{
    uint32 uiSoundId;
    uint8  uiType;
    uint32 uiLanguage;
    uint32 uiEmote;
};

class TC_GAME_API SystemMgr
{
        SystemMgr() {}
        ~SystemMgr() {}

    public:
        //Maps and lists
        typedef std::unordered_map<int32, StringTextData> TextDataMap;
        typedef std::unordered_map<uint32, ScriptPointVector> PointMoveMap;

    static SystemMgr* instance();

        //Database
        void LoadScriptTexts();
        void LoadScriptTextsCustom();
        void LoadScriptWaypoints();

        StringTextData const* GetTextData(int32 textId) const;
        ScriptPointVector const& GetPointMoveList(uint32 creatureEntry) const;

    protected:
        TextDataMap     m_mTextDataMap;                     //additional data for text strings
        PointMoveMap    m_mPointMoveMap;                    //coordinates for waypoints

    private:
        static ScriptPointVector const _empty;
};

#define sScriptSystemMgr SystemMgr::instance()

#endif
