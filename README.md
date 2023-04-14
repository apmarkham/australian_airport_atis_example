# Australian Airport ATIS Example in C++
A simple C++ example of how to request a location briefing for a given Australian airport to provide ATIS and METAR data.

More info can be found on [my blog post](https://www.apmarkham.com/posts/australian-atis-feed/).

Sample output for a YSSY request:

    LOCATION BRIEFING
    
    PREPARED FOR: <USERNAME>
    VALID FROM 1113 UTC APR 14, 2023 TO 1113 UTC APR 15, 2023
    
                                   WEATHER INFORMATION
                                   -------------------
    
    SYDNEY (YSSY)
        TAF YSSY 141108Z 1412/1518
        26008KT 9999 SHOWERS OF LIGHT RAIN FEW020
        FM141500 29007KT 9999 NSW FEW020
        FM142300 35005KT CAVOK
        FM150400 04014KT CAVOK
        FM151200 36007KT CAVOK
        RMK
        T 16 15 14 15 Q 1012 1011 1009 1010
        TAF3
    
        TAF AMD YSSY 141019Z 1410/1512
        18010KT 9999 SHOWERS OF LIGHT RAIN SCT025 BKN035
        FM141100 26008KT 9999 SHOWERS OF LIGHT RAIN FEW025
        FM141500 29007KT 9999 NSW FEW020
        FM142300 35005KT CAVOK
        FM150400 04012KT CAVOK
        RMK
        T 17 17 15 14 Q 1012 1011 1010 1009
        TAF3
    
        METAR YSSY 141100Z 27007KT 9999 SHOWERS IN VICINITY FEW018 SCT060
        17/15 Q1013 RMK
        RF00.0/009.2
    
        ATIS YSSY O   141058
          APCH: EXPECT INSTR APCH THEN INDEPENDENT VISUAL APCH WHEN
                VISUAL. DO NOT PASS THROUGH ASSIGNED RWY CENTRE LINE
          RWY: 16L AND R FOR ARRS AND DEPS
          SFC COND: WET
          OPR INFO: INDEPENDENT PARL DEPARTURES IN PROGRESS.
                    WHEN READY FOR PUSH BACK OR TAXI CTC COORDINATOR
                    127.6
          WIND: VRB/8
          VIS: GT 10KM
          WX: SH IN AREA
          CLD: FEW018, SCT024
          TMP: 17
        + QNH: 1013
        