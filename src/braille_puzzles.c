#include "global.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_camera.h"
#include "field_effect.h"
#include "script.h"
#include "sound.h"
#include "task.h"
#include "constants/field_effects.h"
#include "constants/songs.h"
#include "constants/metatile_labels.h"
#include "fieldmap.h"
#include "party_menu.h"
#include "fldeff.h"

EWRAM_DATA static bool8 sIsRegisteelPuzzle = 0;

static const u8 sRegicePathCoords[][2] =
{
    {4,  21},
    {5,  21},
    {6,  21},
    {7,  21},
    {8,  21},
    {9,  21},
    {10, 21},
    {11, 21},
    {12, 21},
    {12, 22},
    {12, 23},
    {13, 23},
    {13, 24},
    {13, 25},
    {13, 26},
    {13, 27},
    {12, 27},
    {12, 28},
    {4,  29},
    {5,  29},
    {6,  29},
    {7,  29},
    {8,  29},
    {9,  29},
    {10, 29},
    {11, 29},
    {12, 29},
    {4,  28},
    {4,  27},
    {3,  27},
    {3,  26},
    {3,  25},
    {3,  24},
    {3,  23},
    {4,  23},
    {4,  22},
};

static void Task_SealedChamberShakingEffect(u8);
static void DoBrailleRegirockEffect(void);
static void DoBrailleRegisteelEffect(void);

bool8 ShouldDoBrailleDigEffect(void)
{
    if (!FlagGet(FLAG_SYS_BRAILLE_DIG)
     && (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(SEALED_CHAMBER_OUTER_ROOM)
     && gSaveBlock1Ptr->location.mapNum == MAP_NUM(SEALED_CHAMBER_OUTER_ROOM)))
    {
        if (gSaveBlock1Ptr->pos.x == 10 && gSaveBlock1Ptr->pos.y == 3)
            return TRUE;
        if (gSaveBlock1Ptr->pos.x == 9 && gSaveBlock1Ptr->pos.y == 3)
            return TRUE;
        if (gSaveBlock1Ptr->pos.x == 11 && gSaveBlock1Ptr->pos.y == 3)
            return TRUE;
    }

    return FALSE;
}

void DoBrailleDigEffect(void)
{
    MapGridSetMetatileIdAt( 9 + MAP_OFFSET, 1 + MAP_OFFSET, METATILE_Cave_SealedChamberEntrance_TopLeft);
    MapGridSetMetatileIdAt(10 + MAP_OFFSET, 1 + MAP_OFFSET, METATILE_Cave_SealedChamberEntrance_TopMid);
    MapGridSetMetatileIdAt(11 + MAP_OFFSET, 1 + MAP_OFFSET, METATILE_Cave_SealedChamberEntrance_TopRight);
    MapGridSetMetatileIdAt( 9 + MAP_OFFSET, 2 + MAP_OFFSET, METATILE_Cave_SealedChamberEntrance_BottomLeft | MAPGRID_COLLISION_MASK);
    MapGridSetMetatileIdAt(10 + MAP_OFFSET, 2 + MAP_OFFSET, METATILE_Cave_SealedChamberEntrance_BottomMid);
    MapGridSetMetatileIdAt(11 + MAP_OFFSET, 2 + MAP_OFFSET, METATILE_Cave_SealedChamberEntrance_BottomRight | MAPGRID_COLLISION_MASK);
    DrawWholeMapView();
    PlaySE(SE_BANG);
    FlagSet(FLAG_SYS_BRAILLE_DIG);
    UnlockPlayerFieldControls();
}

bool8 CheckRelicanthWailord(void)
{
    // Emerald change: why did they flip it?
    // First comes Wailord
    if (GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_WAILORD)
    {
        CalculatePlayerPartyCount();
        // Last comes Relicanth
        if (GetMonData(&gPlayerParty[gPlayerPartyCount - 1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_RELICANTH)
            return TRUE;
    }
    return FALSE;
}

bool8 CheckDojo(void)
{   
       if (GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MANKEY||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PRIMEAPE
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_POLIWRATH||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PRIMEAPE
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MACHOP||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MACHOKE
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MACHAMP||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_FARFETCHD_GALARIAN
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HITMONLEE||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HITMONCHAN
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_ZAPDOS_GALARIAN||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MEWTWO_MEGA_X
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HERACROSS||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HERACROSS_MEGA
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_SNEASEL_HISUIAN||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HITMONTOP
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_COMBUSKEN||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_BLAZIKEN
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_BLAZIKEN_MEGA||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_BRELOOM
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MAKUHITA||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HARIYAMA
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MEDITITE||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MEDICHAM
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MEDICHAM_MEGA||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MONFERNO
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_INFERNAPE||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_LOPUNNY_MEGA
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_RIOLU||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_LUCARIO
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_LUCARIO_MEGA||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_CROAGUNK
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_TOXICROAK||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_GALLADE
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_GALLADE_MEGA||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PIGNITE
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_EMBOAR||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_TIMBURR
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_GURDURR||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_CONKELDURR
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_THROH||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_SAWK
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_LILLIGANT_HISUIAN||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_SCRAGGY
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_SCRAFTY||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MIENFOO
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MIENSHAO||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_COBALION
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_TERRAKION||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_VIRIZION
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_KELDEO||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_KELDEO_RESOLUTE
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MELOETTA_PIROUETTE||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_CHESNAUGHT
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PANCHAM||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PANGORO
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HAWLUCHA||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_DECIDUEYE_HISUIAN
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_CRABRAWLER||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_CRABOMINABLE
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_STUFFUL||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_BEWEAR
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PASSIMIAN||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HAKAMO_O
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_KOMMO_O||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_BUZZWOLE
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PHEROMOSA||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MARSHADOW
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_CLOBBOPUS||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_GRAPPLOCT
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_SIRFETCHD||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_FALINKS
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_ZAMAZENTA||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_ZAMAZENTA_CROWNED_SHIELD
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_KUBFU||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_URSHIFU
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_URSHIFU_RAPID_STRIKE_STYLE||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_SNEASLER
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_QUAQUAVAL||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PAWMO
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PAWMOT||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_FLAMIGO
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_ANNIHILAPE||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_GREAT_TUSK
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_SLITHER_WING||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_IRON_HANDS
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_IRON_VALIANT||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_KORAIDON
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_OKIDOGI ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_TAUROS_PALDEAN_AQUA_BREED
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_TAUROS_PALDEAN_BLAZE_BREED ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_TAUROS_PALDEAN_COMBAT_BREED)
        {
                   if (GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MANKEY||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PRIMEAPE
       ||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_POLIWRATH||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PRIMEAPE
       ||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MACHOP||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MACHOKE
       ||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MACHAMP||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_FARFETCHD_GALARIAN
       ||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HITMONLEE||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HITMONCHAN
       ||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_ZAPDOS_GALARIAN||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MEWTWO_MEGA_X
       ||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HERACROSS||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HERACROSS_MEGA
       ||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_SNEASEL_HISUIAN||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HITMONTOP
       ||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_COMBUSKEN||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_BLAZIKEN
       ||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_BLAZIKEN_MEGA||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_BRELOOM
       ||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MAKUHITA||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HARIYAMA
       ||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MEDITITE||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MEDICHAM
       ||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MEDICHAM_MEGA||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MONFERNO
       ||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_INFERNAPE||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_LOPUNNY_MEGA
       ||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_RIOLU||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_LUCARIO
       ||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_LUCARIO_MEGA||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_CROAGUNK
       ||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_TOXICROAK||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_GALLADE
       ||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_GALLADE_MEGA||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PIGNITE
       ||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_EMBOAR||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_TIMBURR
       ||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_GURDURR||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_CONKELDURR
       ||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_THROH||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_SAWK
       ||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_LILLIGANT_HISUIAN||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_SCRAGGY
       ||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_SCRAFTY||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MIENFOO
       ||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MIENSHAO||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_COBALION
       ||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_TERRAKION||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_VIRIZION
       ||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_KELDEO||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_KELDEO_RESOLUTE
       ||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MELOETTA_PIROUETTE||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_CHESNAUGHT
       ||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PANCHAM||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PANGORO
       ||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HAWLUCHA||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_DECIDUEYE_HISUIAN
       ||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_CRABRAWLER||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_CRABOMINABLE
       ||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_STUFFUL||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_BEWEAR
       ||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PASSIMIAN||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HAKAMO_O
       ||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_KOMMO_O||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_BUZZWOLE
       ||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PHEROMOSA||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MARSHADOW
       ||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_CLOBBOPUS||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_GRAPPLOCT
       ||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_SIRFETCHD||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_FALINKS
       ||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_ZAMAZENTA||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_ZAMAZENTA_CROWNED_SHIELD
       ||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_KUBFU||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_URSHIFU
       ||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_URSHIFU_RAPID_STRIKE_STYLE||GetMonData(&gPlayerParty[1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_SNEASLER       
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_QUAQUAVAL||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PAWMO
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PAWMOT||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_FLAMIGO
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_ANNIHILAPE||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_GREAT_TUSK
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_SLITHER_WING||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_IRON_HANDS
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_IRON_VALIANT||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_KORAIDON
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_OKIDOGI||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_TAUROS_PALDEAN_AQUA_BREED
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_TAUROS_PALDEAN_BLAZE_BREED ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_TAUROS_PALDEAN_COMBAT_BREED){
                               if (GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MANKEY||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PRIMEAPE
       ||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_POLIWRATH||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PRIMEAPE
       ||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MACHOP||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MACHOKE
       ||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MACHAMP||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_FARFETCHD_GALARIAN
       ||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HITMONLEE||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HITMONCHAN
       ||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_ZAPDOS_GALARIAN||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MEWTWO_MEGA_X
       ||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HERACROSS||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HERACROSS_MEGA
       ||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_SNEASEL_HISUIAN||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HITMONTOP
       ||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_COMBUSKEN||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_BLAZIKEN
       ||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_BLAZIKEN_MEGA||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_BRELOOM
       ||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MAKUHITA||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HARIYAMA
       ||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MEDITITE||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MEDICHAM
       ||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MEDICHAM_MEGA||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MONFERNO
       ||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_INFERNAPE||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_LOPUNNY_MEGA
       ||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_RIOLU||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_LUCARIO
       ||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_LUCARIO_MEGA||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_CROAGUNK
       ||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_TOXICROAK||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_GALLADE
       ||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_GALLADE_MEGA||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PIGNITE
       ||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_EMBOAR||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_TIMBURR
       ||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_GURDURR||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_CONKELDURR
       ||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_THROH||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_SAWK
       ||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_LILLIGANT_HISUIAN||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_SCRAGGY
       ||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_SCRAFTY||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MIENFOO
       ||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MIENSHAO||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_COBALION
       ||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_TERRAKION||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_VIRIZION
       ||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_KELDEO||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_KELDEO_RESOLUTE
       ||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MELOETTA_PIROUETTE||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_CHESNAUGHT
       ||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PANCHAM||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PANGORO
       ||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HAWLUCHA||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_DECIDUEYE_HISUIAN
       ||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_CRABRAWLER||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_CRABOMINABLE
       ||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_STUFFUL||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_BEWEAR
       ||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PASSIMIAN||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HAKAMO_O
       ||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_KOMMO_O||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_BUZZWOLE
       ||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PHEROMOSA||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MARSHADOW
       ||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_CLOBBOPUS||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_GRAPPLOCT
       ||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_SIRFETCHD||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_FALINKS
       ||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_ZAMAZENTA||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_ZAMAZENTA_CROWNED_SHIELD
       ||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_KUBFU||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_URSHIFU
       ||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_URSHIFU_RAPID_STRIKE_STYLE||GetMonData(&gPlayerParty[2], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_SNEASLER       
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_QUAQUAVAL||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PAWMO
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PAWMOT||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_FLAMIGO
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_ANNIHILAPE||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_GREAT_TUSK
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_SLITHER_WING||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_IRON_HANDS
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_IRON_VALIANT||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_KORAIDON
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_OKIDOGI||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_TAUROS_PALDEAN_AQUA_BREED
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_TAUROS_PALDEAN_BLAZE_BREED ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_TAUROS_PALDEAN_COMBAT_BREED){
                                   if (GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MANKEY||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PRIMEAPE
       ||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_POLIWRATH||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PRIMEAPE
       ||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MACHOP||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MACHOKE
       ||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MACHAMP||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_FARFETCHD_GALARIAN
       ||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HITMONLEE||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HITMONCHAN
       ||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_ZAPDOS_GALARIAN||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MEWTWO_MEGA_X
       ||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HERACROSS||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HERACROSS_MEGA
       ||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_SNEASEL_HISUIAN||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HITMONTOP
       ||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_COMBUSKEN||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_BLAZIKEN
       ||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_BLAZIKEN_MEGA||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_BRELOOM
       ||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MAKUHITA||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HARIYAMA
       ||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MEDITITE||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MEDICHAM
       ||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MEDICHAM_MEGA||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MONFERNO
       ||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_INFERNAPE||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_LOPUNNY_MEGA
       ||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_RIOLU||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_LUCARIO
       ||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_LUCARIO_MEGA||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_CROAGUNK
       ||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_TOXICROAK||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_GALLADE
       ||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_GALLADE_MEGA||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PIGNITE
       ||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_EMBOAR||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_TIMBURR
       ||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_GURDURR||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_CONKELDURR
       ||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_THROH||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_SAWK
       ||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_LILLIGANT_HISUIAN||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_SCRAGGY
       ||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_SCRAFTY||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MIENFOO
       ||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MIENSHAO||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_COBALION
       ||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_TERRAKION||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_VIRIZION
       ||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_KELDEO||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_KELDEO_RESOLUTE
       ||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MELOETTA_PIROUETTE||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_CHESNAUGHT
       ||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PANCHAM||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PANGORO
       ||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HAWLUCHA||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_DECIDUEYE_HISUIAN
       ||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_CRABRAWLER||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_CRABOMINABLE
       ||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_STUFFUL||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_BEWEAR
       ||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PASSIMIAN||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HAKAMO_O
       ||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_KOMMO_O||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_BUZZWOLE
       ||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PHEROMOSA||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MARSHADOW
       ||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_CLOBBOPUS||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_GRAPPLOCT
       ||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_SIRFETCHD||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_FALINKS
       ||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_ZAMAZENTA||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_ZAMAZENTA_CROWNED_SHIELD
       ||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_KUBFU||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_URSHIFU
       ||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_URSHIFU_RAPID_STRIKE_STYLE||GetMonData(&gPlayerParty[3], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_SNEASLER       
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_QUAQUAVAL||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PAWMO
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PAWMOT||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_FLAMIGO
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_ANNIHILAPE||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_GREAT_TUSK
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_SLITHER_WING||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_IRON_HANDS
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_IRON_VALIANT||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_KORAIDON
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_OKIDOGI||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_TAUROS_PALDEAN_AQUA_BREED
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_TAUROS_PALDEAN_BLAZE_BREED ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_TAUROS_PALDEAN_COMBAT_BREED){
                   if (GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MANKEY||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PRIMEAPE
       ||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_POLIWRATH||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PRIMEAPE
       ||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MACHOP||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MACHOKE
       ||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MACHAMP||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_FARFETCHD_GALARIAN
       ||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HITMONLEE||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HITMONCHAN
       ||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_ZAPDOS_GALARIAN||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MEWTWO_MEGA_X
       ||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HERACROSS||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HERACROSS_MEGA
       ||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_SNEASEL_HISUIAN||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HITMONTOP
       ||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_COMBUSKEN||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_BLAZIKEN
       ||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_BLAZIKEN_MEGA||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_BRELOOM
       ||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MAKUHITA||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HARIYAMA
       ||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MEDITITE||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MEDICHAM
       ||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MEDICHAM_MEGA||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MONFERNO
       ||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_INFERNAPE||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_LOPUNNY_MEGA
       ||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_RIOLU||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_LUCARIO
       ||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_LUCARIO_MEGA||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_CROAGUNK
       ||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_TOXICROAK||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_GALLADE
       ||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_GALLADE_MEGA||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PIGNITE
       ||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_EMBOAR||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_TIMBURR
       ||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_GURDURR||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_CONKELDURR
       ||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_THROH||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_SAWK
       ||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_LILLIGANT_HISUIAN||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_SCRAGGY
       ||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_SCRAFTY||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MIENFOO
       ||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MIENSHAO||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_COBALION
       ||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_TERRAKION||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_VIRIZION
       ||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_KELDEO||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_KELDEO_RESOLUTE
       ||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MELOETTA_PIROUETTE||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_CHESNAUGHT
       ||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PANCHAM||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PANGORO
       ||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HAWLUCHA||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_DECIDUEYE_HISUIAN
       ||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_CRABRAWLER||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_CRABOMINABLE
       ||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_STUFFUL||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_BEWEAR
       ||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PASSIMIAN||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HAKAMO_O
       ||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_KOMMO_O||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_BUZZWOLE
       ||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PHEROMOSA||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MARSHADOW
       ||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_CLOBBOPUS||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_GRAPPLOCT
       ||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_SIRFETCHD||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_FALINKS
       ||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_ZAMAZENTA||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_ZAMAZENTA_CROWNED_SHIELD
       ||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_KUBFU||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_URSHIFU
       ||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_URSHIFU_RAPID_STRIKE_STYLE||GetMonData(&gPlayerParty[4], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_SNEASLER       
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_QUAQUAVAL||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PAWMO
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PAWMOT||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_FLAMIGO
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_ANNIHILAPE||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_GREAT_TUSK
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_SLITHER_WING||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_IRON_HANDS
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_IRON_VALIANT||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_KORAIDON
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_OKIDOGI||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_TAUROS_PALDEAN_AQUA_BREED
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_TAUROS_PALDEAN_BLAZE_BREED ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_TAUROS_PALDEAN_COMBAT_BREED){
                   if (GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MANKEY||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PRIMEAPE
       ||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_POLIWRATH||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PRIMEAPE
       ||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MACHOP||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MACHOKE
       ||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MACHAMP||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_FARFETCHD_GALARIAN
       ||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HITMONLEE||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HITMONCHAN
       ||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_ZAPDOS_GALARIAN||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MEWTWO_MEGA_X
       ||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HERACROSS||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HERACROSS_MEGA
       ||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_SNEASEL_HISUIAN||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HITMONTOP
       ||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_COMBUSKEN||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_BLAZIKEN
       ||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_BLAZIKEN_MEGA||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_BRELOOM
       ||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MAKUHITA||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HARIYAMA
       ||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MEDITITE||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MEDICHAM
       ||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MEDICHAM_MEGA||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MONFERNO
       ||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_INFERNAPE||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_LOPUNNY_MEGA
       ||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_RIOLU||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_LUCARIO
       ||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_LUCARIO_MEGA||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_CROAGUNK
       ||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_TOXICROAK||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_GALLADE
       ||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_GALLADE_MEGA||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PIGNITE
       ||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_EMBOAR||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_TIMBURR
       ||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_GURDURR||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_CONKELDURR
       ||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_THROH||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_SAWK
       ||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_LILLIGANT_HISUIAN||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_SCRAGGY
       ||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_SCRAFTY||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MIENFOO
       ||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MIENSHAO||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_COBALION
       ||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_TERRAKION||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_VIRIZION
       ||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_KELDEO||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_KELDEO_RESOLUTE
       ||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MELOETTA_PIROUETTE||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_CHESNAUGHT
       ||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PANCHAM||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PANGORO
       ||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HAWLUCHA||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_DECIDUEYE_HISUIAN
       ||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_CRABRAWLER||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_CRABOMINABLE
       ||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_STUFFUL||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_BEWEAR
       ||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PASSIMIAN||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_HAKAMO_O
       ||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_KOMMO_O||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_BUZZWOLE
       ||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PHEROMOSA||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_MARSHADOW
       ||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_CLOBBOPUS||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_GRAPPLOCT
       ||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_SIRFETCHD||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_FALINKS
       ||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_ZAMAZENTA||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_ZAMAZENTA_CROWNED_SHIELD
       ||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_KUBFU||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_URSHIFU
       ||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_URSHIFU_RAPID_STRIKE_STYLE||GetMonData(&gPlayerParty[5], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_SNEASLER       
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_QUAQUAVAL||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PAWMO
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_PAWMOT||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_FLAMIGO
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_ANNIHILAPE||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_GREAT_TUSK
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_SLITHER_WING||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_IRON_HANDS
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_IRON_VALIANT||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_KORAIDON
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_OKIDOGI||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_TAUROS_PALDEAN_AQUA_BREED
       ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_TAUROS_PALDEAN_BLAZE_BREED ||GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_TAUROS_PALDEAN_COMBAT_BREED){
                            return TRUE;
                      }
                   }
                }
            }
         }
        }
    return FALSE;
}

// THEORY: this was caused by block commenting out all of the older R/S braille functions but leaving the call to it itself, which creates the nullsub.
void ShouldDoBrailleRegirockEffectOld(void)
{
}

#define tDelayCounter  data[1]
#define tShakeCounter  data[2]
#define tVerticalPan   data[4]
#define tDelay         data[5]
#define tNumShakes     data[6]

void DoSealedChamberShakingEffect_Long(void)
{
    u8 taskId = CreateTask(Task_SealedChamberShakingEffect, 9);

    gTasks[taskId].tDelayCounter = 0;
    gTasks[taskId].tShakeCounter = 0;
    gTasks[taskId].tVerticalPan = 2;
    gTasks[taskId].tDelay = 5;
    gTasks[taskId].tNumShakes = 50;
    SetCameraPanningCallback(0);
}

void DoSealedChamberShakingEffect_Short(void)
{
    u8 taskId = CreateTask(Task_SealedChamberShakingEffect, 9);

    gTasks[taskId].tDelayCounter = 0;
    gTasks[taskId].tShakeCounter = 0;
    gTasks[taskId].tVerticalPan = 3;
    gTasks[taskId].tDelay = 5;
    gTasks[taskId].tNumShakes = 2;
    SetCameraPanningCallback(0);
}

static void Task_SealedChamberShakingEffect(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    task->tDelayCounter++;
    if (task->tDelayCounter % task->tDelay == 0)
    {
        task->tDelayCounter = 0;
        task->tShakeCounter++;
        task->tVerticalPan = -task->tVerticalPan;
        SetCameraPanning(0, task->tVerticalPan);
        if (task->tShakeCounter == task->tNumShakes)
        {
            DestroyTask(taskId);
            ScriptContext_Enable();
            InstallCameraPanAheadCallback();
        }
    }
}

#undef tDelayCounter
#undef tShakeCounter
#undef tVerticalPan
#undef tDelay
#undef tNumShakes

bool8 ShouldDoBrailleRegirockEffect(void)
{
    if (!FlagGet(FLAG_SYS_REGIROCK_PUZZLE_COMPLETED)
        && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(DESERT_RUINS)
        && gSaveBlock1Ptr->location.mapNum == MAP_NUM(DESERT_RUINS))
    {
        if (gSaveBlock1Ptr->pos.x == 6 && gSaveBlock1Ptr->pos.y == 23)
        {
            sIsRegisteelPuzzle = FALSE;
            return TRUE;
        }
        else if (gSaveBlock1Ptr->pos.x == 5 && gSaveBlock1Ptr->pos.y == 23)
        {
            sIsRegisteelPuzzle = FALSE;
            return TRUE;
        }
        else if (gSaveBlock1Ptr->pos.x == 7 && gSaveBlock1Ptr->pos.y == 23)
        {
            sIsRegisteelPuzzle = FALSE;
            return TRUE;
        }
    }

    return FALSE;
}

void SetUpPuzzleEffectRegirock(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    FieldEffectStart(FLDEFF_USE_TOMB_PUZZLE_EFFECT);
}

void UseRegirockHm_Callback(void)
{
    FieldEffectActiveListRemove(FLDEFF_USE_TOMB_PUZZLE_EFFECT);
    DoBrailleRegirockEffect();
}

static void DoBrailleRegirockEffect(void)
{
    MapGridSetMetatileIdAt(7 + MAP_OFFSET, 19 + MAP_OFFSET, METATILE_Cave_SealedChamberEntrance_TopLeft);
    MapGridSetMetatileIdAt(8 + MAP_OFFSET, 19 + MAP_OFFSET, METATILE_Cave_SealedChamberEntrance_TopMid);
    MapGridSetMetatileIdAt(9 + MAP_OFFSET, 19 + MAP_OFFSET, METATILE_Cave_SealedChamberEntrance_TopRight);
    MapGridSetMetatileIdAt(7 + MAP_OFFSET, 20 + MAP_OFFSET, METATILE_Cave_SealedChamberEntrance_BottomLeft | MAPGRID_COLLISION_MASK);
    MapGridSetMetatileIdAt(8 + MAP_OFFSET, 20 + MAP_OFFSET, METATILE_Cave_SealedChamberEntrance_BottomMid);
    MapGridSetMetatileIdAt(9 + MAP_OFFSET, 20 + MAP_OFFSET, METATILE_Cave_SealedChamberEntrance_BottomRight | MAPGRID_COLLISION_MASK);
    DrawWholeMapView();
    PlaySE(SE_BANG);
    FlagSet(FLAG_SYS_REGIROCK_PUZZLE_COMPLETED);
    UnlockPlayerFieldControls();
    UnfreezeObjectEvents();
}

bool8 ShouldDoBrailleRegisteelEffect(void)
{
    if (!FlagGet(FLAG_SYS_REGISTEEL_PUZZLE_COMPLETED) && (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ANCIENT_TOMB) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(ANCIENT_TOMB)))
    {
        if (gSaveBlock1Ptr->pos.x == 8 && gSaveBlock1Ptr->pos.y == 25)
        {
            sIsRegisteelPuzzle = TRUE;
            return TRUE;
        }
    }
    return FALSE;
}

void SetUpPuzzleEffectRegisteel(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    FieldEffectStart(FLDEFF_USE_TOMB_PUZZLE_EFFECT);
}

void UseRegisteelHm_Callback(void)
{
    FieldEffectActiveListRemove(FLDEFF_USE_TOMB_PUZZLE_EFFECT);
    DoBrailleRegisteelEffect();
}

static void DoBrailleRegisteelEffect(void)
{
    MapGridSetMetatileIdAt(7 + MAP_OFFSET, 19 + MAP_OFFSET, METATILE_Cave_SealedChamberEntrance_TopLeft);
    MapGridSetMetatileIdAt(8 + MAP_OFFSET, 19 + MAP_OFFSET, METATILE_Cave_SealedChamberEntrance_TopMid);
    MapGridSetMetatileIdAt(9 + MAP_OFFSET, 19 + MAP_OFFSET, METATILE_Cave_SealedChamberEntrance_TopRight);
    MapGridSetMetatileIdAt(7 + MAP_OFFSET, 20 + MAP_OFFSET, METATILE_Cave_SealedChamberEntrance_BottomLeft | MAPGRID_COLLISION_MASK);
    MapGridSetMetatileIdAt(8 + MAP_OFFSET, 20 + MAP_OFFSET, METATILE_Cave_SealedChamberEntrance_BottomMid);
    MapGridSetMetatileIdAt(9 + MAP_OFFSET, 20 + MAP_OFFSET, METATILE_Cave_SealedChamberEntrance_BottomRight | MAPGRID_COLLISION_MASK);
    DrawWholeMapView();
    PlaySE(SE_BANG);
    FlagSet(FLAG_SYS_REGISTEEL_PUZZLE_COMPLETED);
    UnlockPlayerFieldControls();
    UnfreezeObjectEvents();
}

// theory: another commented out DoBrailleWait and Task_BrailleWait.
static void UNUSED DoBrailleWait(void)
{
}

// this used to be FldEff_UseFlyAncientTomb . why did GF merge the 2 functions?
bool8 FldEff_UsePuzzleEffect(void)
{
    u8 taskId = CreateFieldMoveTask();

    if (sIsRegisteelPuzzle == TRUE)
    {
        gTasks[taskId].data[8] = (u32)UseRegisteelHm_Callback >> 16;
        gTasks[taskId].data[9] = (u32)UseRegisteelHm_Callback;
    }
    else
    {
        gTasks[taskId].data[8] = (u32)UseRegirockHm_Callback >> 16;
        gTasks[taskId].data[9] = (u32)UseRegirockHm_Callback;
    }
    return FALSE;
}

// The puzzle to unlock Regice's cave requires the player to interact with the braille message on the back wall,
// step on every space on the perimeter of the cave (and only those spaces) then return to the back wall.
bool8 ShouldDoBrailleRegicePuzzle(void)
{
    u8 i;

    if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ISLAND_CAVE)
        && gSaveBlock1Ptr->location.mapNum == MAP_NUM(ISLAND_CAVE))
    {
        if (FlagGet(FLAG_SYS_BRAILLE_REGICE_COMPLETED))
            return FALSE;
        // Set when the player interacts with the braille message
        if (FlagGet(FLAG_TEMP_REGICE_PUZZLE_STARTED) == FALSE)
            return FALSE;
        // Cleared when the player interacts with the braille message
        if (FlagGet(FLAG_TEMP_REGICE_PUZZLE_FAILED) == TRUE)
            return FALSE;

        for (i = 0; i < ARRAY_COUNT(sRegicePathCoords); i++)
        {
            u8 xPos = sRegicePathCoords[i][0];
            u8 yPos = sRegicePathCoords[i][1];
            if (gSaveBlock1Ptr->pos.x == xPos && gSaveBlock1Ptr->pos.y == yPos)
            {
                // Player is standing on a correct space, set the corresponding bit
                if (i < 16)
                {
                    u16 val = VarGet(VAR_REGICE_STEPS_1);
                    val |= 1 << i;
                    VarSet(VAR_REGICE_STEPS_1, val);
                }
                else if (i < 32)
                {
                    u16 val = VarGet(VAR_REGICE_STEPS_2);
                    val |= 1 << (i - 16);
                    VarSet(VAR_REGICE_STEPS_2, val);
                }
                else
                {
                    u16 val = VarGet(VAR_REGICE_STEPS_3);
                    val |= 1 << (i - 32);
                    VarSet(VAR_REGICE_STEPS_3, val);
                }

                // Make sure a full lap has been completed. There are 36 steps in a lap, so 16+16+4 bits to check across the 3 vars.
                if (VarGet(VAR_REGICE_STEPS_1) != 0xFFFF || VarGet(VAR_REGICE_STEPS_2) != 0xFFFF || VarGet(VAR_REGICE_STEPS_3) != 0xF)
                    return FALSE;

                // A lap has been completed, the puzzle is complete when the player returns to the braille message.
                if (gSaveBlock1Ptr->pos.x == 8 && gSaveBlock1Ptr->pos.y == 21)
                    return TRUE;
                else
                    return FALSE;
            }
        }

        // Player stepped on an incorrect space, puzzle failed.
        FlagSet(FLAG_TEMP_REGICE_PUZZLE_FAILED);
        FlagClear(FLAG_TEMP_REGICE_PUZZLE_STARTED);
    }

    return FALSE;
}
