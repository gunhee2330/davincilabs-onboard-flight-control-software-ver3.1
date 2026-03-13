    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 73;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (UAM_Flight_control_P)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.controlParams
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.uavParam
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.control
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.FWControlParams
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Cruise_a
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_P.FWTrimSpeed
                    section.data(2).logicalSrcIdx = 5;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_P.Vt
                    section.data(3).logicalSrcIdx = 6;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_P.w_trim
                    section.data(4).logicalSrcIdx = 7;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_P.zGround
                    section.data(5).logicalSrcIdx = 8;
                    section.data(5).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.FSState
                    section.data(1).logicalSrcIdx = 9;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section

            section.nData     = 131;
            section.data(131)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.PitchAngleController_InitialCon
                    section.data(1).logicalSrcIdx = 10;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_P.Altituderatecontroller_InitialC
                    section.data(2).logicalSrcIdx = 11;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_P.Lateralvelocitycontroller_Initi
                    section.data(3).logicalSrcIdx = 12;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_P.Forwardvelocitycontroller_Initi
                    section.data(4).logicalSrcIdx = 13;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_P.Pitchratecontroller_InitialCond
                    section.data(5).logicalSrcIdx = 14;
                    section.data(5).dtTransOffset = 4;

                    ;% UAM_Flight_control_P.Rollratecontroller_InitialCondi
                    section.data(6).logicalSrcIdx = 15;
                    section.data(6).dtTransOffset = 5;

                    ;% UAM_Flight_control_P.AirspeedController_InitialCondi
                    section.data(7).logicalSrcIdx = 16;
                    section.data(7).dtTransOffset = 6;

                    ;% UAM_Flight_control_P.PitchAngleController_InitialC_p
                    section.data(8).logicalSrcIdx = 17;
                    section.data(8).dtTransOffset = 7;

                    ;% UAM_Flight_control_P.AirspeedController_InitialCon_a
                    section.data(9).logicalSrcIdx = 18;
                    section.data(9).dtTransOffset = 8;

                    ;% UAM_Flight_control_P.Altituderatecontroller_Initia_g
                    section.data(10).logicalSrcIdx = 19;
                    section.data(10).dtTransOffset = 9;

                    ;% UAM_Flight_control_P.Forwardvelocitycontroller_Ini_a
                    section.data(11).logicalSrcIdx = 20;
                    section.data(11).dtTransOffset = 10;

                    ;% UAM_Flight_control_P.Lateralvelocitycontroller_Ini_p
                    section.data(12).logicalSrcIdx = 21;
                    section.data(12).dtTransOffset = 11;

                    ;% UAM_Flight_control_P.PitchRateController_InitialCond
                    section.data(13).logicalSrcIdx = 22;
                    section.data(13).dtTransOffset = 12;

                    ;% UAM_Flight_control_P.RollRateController_InitialCondi
                    section.data(14).logicalSrcIdx = 23;
                    section.data(14).dtTransOffset = 13;

                    ;% UAM_Flight_control_P.PitchAngleController_Initial_pa
                    section.data(15).logicalSrcIdx = 24;
                    section.data(15).dtTransOffset = 14;

                    ;% UAM_Flight_control_P.Yawratecontroller_InitialCondit
                    section.data(16).logicalSrcIdx = 25;
                    section.data(16).dtTransOffset = 15;

                    ;% UAM_Flight_control_P.PitchAngleController_InitialC_d
                    section.data(17).logicalSrcIdx = 26;
                    section.data(17).dtTransOffset = 16;

                    ;% UAM_Flight_control_P.Altituderatecontroller_Initia_j
                    section.data(18).logicalSrcIdx = 27;
                    section.data(18).dtTransOffset = 17;

                    ;% UAM_Flight_control_P.Lateralvelocitycontroller_Ini_k
                    section.data(19).logicalSrcIdx = 28;
                    section.data(19).dtTransOffset = 18;

                    ;% UAM_Flight_control_P.Forwardvelocitycontroller_Ini_i
                    section.data(20).logicalSrcIdx = 29;
                    section.data(20).dtTransOffset = 19;

                    ;% UAM_Flight_control_P.Yawratecontroller_InitialCond_c
                    section.data(21).logicalSrcIdx = 30;
                    section.data(21).dtTransOffset = 20;

                    ;% UAM_Flight_control_P.Pitchratecontroller_InitialCo_i
                    section.data(22).logicalSrcIdx = 31;
                    section.data(22).dtTransOffset = 21;

                    ;% UAM_Flight_control_P.Rollratecontroller_InitialCon_e
                    section.data(23).logicalSrcIdx = 32;
                    section.data(23).dtTransOffset = 22;

                    ;% UAM_Flight_control_P.AirspeedController_InitialCon_l
                    section.data(24).logicalSrcIdx = 33;
                    section.data(24).dtTransOffset = 23;

                    ;% UAM_Flight_control_P.PitchAngleController_InitialC_c
                    section.data(25).logicalSrcIdx = 34;
                    section.data(25).dtTransOffset = 24;

                    ;% UAM_Flight_control_P.AirspeedController_InitialCon_f
                    section.data(26).logicalSrcIdx = 35;
                    section.data(26).dtTransOffset = 25;

                    ;% UAM_Flight_control_P.Altituderatecontroller_Initia_k
                    section.data(27).logicalSrcIdx = 36;
                    section.data(27).dtTransOffset = 26;

                    ;% UAM_Flight_control_P.Forwardvelocitycontroller_Ini_o
                    section.data(28).logicalSrcIdx = 37;
                    section.data(28).dtTransOffset = 27;

                    ;% UAM_Flight_control_P.Lateralvelocitycontroller_Ini_m
                    section.data(29).logicalSrcIdx = 38;
                    section.data(29).dtTransOffset = 28;

                    ;% UAM_Flight_control_P.Yawratecontroller_InitialCond_a
                    section.data(30).logicalSrcIdx = 39;
                    section.data(30).dtTransOffset = 29;

                    ;% UAM_Flight_control_P.PitchRateController_InitialCo_m
                    section.data(31).logicalSrcIdx = 40;
                    section.data(31).dtTransOffset = 30;

                    ;% UAM_Flight_control_P.RollRateController_InitialCon_j
                    section.data(32).logicalSrcIdx = 41;
                    section.data(32).dtTransOffset = 31;

                    ;% UAM_Flight_control_P.PitchAngleController_InitialC_f
                    section.data(33).logicalSrcIdx = 42;
                    section.data(33).dtTransOffset = 32;

                    ;% UAM_Flight_control_P.Altituderatecontroller_LowerInt
                    section.data(34).logicalSrcIdx = 43;
                    section.data(34).dtTransOffset = 33;

                    ;% UAM_Flight_control_P.Lateralvelocitycontroller_Lower
                    section.data(35).logicalSrcIdx = 44;
                    section.data(35).dtTransOffset = 34;

                    ;% UAM_Flight_control_P.Forwardvelocitycontroller_Lower
                    section.data(36).logicalSrcIdx = 45;
                    section.data(36).dtTransOffset = 35;

                    ;% UAM_Flight_control_P.Yawratecontroller_LowerIntegrat
                    section.data(37).logicalSrcIdx = 46;
                    section.data(37).dtTransOffset = 36;

                    ;% UAM_Flight_control_P.Pitchratecontroller_LowerIntegr
                    section.data(38).logicalSrcIdx = 47;
                    section.data(38).dtTransOffset = 37;

                    ;% UAM_Flight_control_P.Rollratecontroller_LowerIntegra
                    section.data(39).logicalSrcIdx = 48;
                    section.data(39).dtTransOffset = 38;

                    ;% UAM_Flight_control_P.Altituderatecontroller_LowerI_o
                    section.data(40).logicalSrcIdx = 49;
                    section.data(40).dtTransOffset = 39;

                    ;% UAM_Flight_control_P.Forwardvelocitycontroller_Low_e
                    section.data(41).logicalSrcIdx = 50;
                    section.data(41).dtTransOffset = 40;

                    ;% UAM_Flight_control_P.Lateralvelocitycontroller_Low_c
                    section.data(42).logicalSrcIdx = 51;
                    section.data(42).dtTransOffset = 41;

                    ;% UAM_Flight_control_P.Yawratecontroller_LowerIntegr_o
                    section.data(43).logicalSrcIdx = 52;
                    section.data(43).dtTransOffset = 42;

                    ;% UAM_Flight_control_P.PitchRateController_LowerIntegr
                    section.data(44).logicalSrcIdx = 53;
                    section.data(44).dtTransOffset = 43;

                    ;% UAM_Flight_control_P.RollRateController_LowerIntegra
                    section.data(45).logicalSrcIdx = 54;
                    section.data(45).dtTransOffset = 44;

                    ;% UAM_Flight_control_P.PitchAngleController_LowerSatur
                    section.data(46).logicalSrcIdx = 55;
                    section.data(46).dtTransOffset = 45;

                    ;% UAM_Flight_control_P.PitchRateController_LowerSatura
                    section.data(47).logicalSrcIdx = 56;
                    section.data(47).dtTransOffset = 46;

                    ;% UAM_Flight_control_P.RudderController_LowerSaturatio
                    section.data(48).logicalSrcIdx = 57;
                    section.data(48).dtTransOffset = 47;

                    ;% UAM_Flight_control_P.RollRateController_LowerSaturat
                    section.data(49).logicalSrcIdx = 58;
                    section.data(49).dtTransOffset = 48;

                    ;% UAM_Flight_control_P.Altituderatecontroller_LowerSat
                    section.data(50).logicalSrcIdx = 59;
                    section.data(50).dtTransOffset = 49;

                    ;% UAM_Flight_control_P.Lateralpositioncontroller_Lower
                    section.data(51).logicalSrcIdx = 60;
                    section.data(51).dtTransOffset = 50;

                    ;% UAM_Flight_control_P.Lateralvelocitycontroller_Low_p
                    section.data(52).logicalSrcIdx = 61;
                    section.data(52).dtTransOffset = 51;

                    ;% UAM_Flight_control_P.Forwardvelocitycontroller_Low_p
                    section.data(53).logicalSrcIdx = 62;
                    section.data(53).dtTransOffset = 52;

                    ;% UAM_Flight_control_P.RudderController_LowerSaturat_e
                    section.data(54).logicalSrcIdx = 63;
                    section.data(54).dtTransOffset = 53;

                    ;% UAM_Flight_control_P.PitchAngleController_LowerSat_a
                    section.data(55).logicalSrcIdx = 64;
                    section.data(55).dtTransOffset = 54;

                    ;% UAM_Flight_control_P.PitchRateController_LowerSatu_k
                    section.data(56).logicalSrcIdx = 65;
                    section.data(56).dtTransOffset = 55;

                    ;% UAM_Flight_control_P.RollRateController_LowerSatur_c
                    section.data(57).logicalSrcIdx = 66;
                    section.data(57).dtTransOffset = 56;

                    ;% UAM_Flight_control_P.Altitudecontroller_LowerSaturat
                    section.data(58).logicalSrcIdx = 67;
                    section.data(58).dtTransOffset = 57;

                    ;% UAM_Flight_control_P.Altituderatecontroller_LowerS_h
                    section.data(59).logicalSrcIdx = 68;
                    section.data(59).dtTransOffset = 58;

                    ;% UAM_Flight_control_P.Forwardpositioncontroller_Lower
                    section.data(60).logicalSrcIdx = 69;
                    section.data(60).dtTransOffset = 59;

                    ;% UAM_Flight_control_P.Lateralpositioncontroller_Low_j
                    section.data(61).logicalSrcIdx = 70;
                    section.data(61).dtTransOffset = 60;

                    ;% UAM_Flight_control_P.Forwardvelocitycontroller_Lo_ei
                    section.data(62).logicalSrcIdx = 71;
                    section.data(62).dtTransOffset = 61;

                    ;% UAM_Flight_control_P.Lateralvelocitycontroller_Low_o
                    section.data(63).logicalSrcIdx = 72;
                    section.data(63).dtTransOffset = 62;

                    ;% UAM_Flight_control_P.Yawratecontroller_LowerSaturati
                    section.data(64).logicalSrcIdx = 73;
                    section.data(64).dtTransOffset = 63;

                    ;% UAM_Flight_control_P.PitchController_LowerSaturation
                    section.data(65).logicalSrcIdx = 74;
                    section.data(65).dtTransOffset = 64;

                    ;% UAM_Flight_control_P.PitchRateController_LowerSatu_h
                    section.data(66).logicalSrcIdx = 75;
                    section.data(66).dtTransOffset = 65;

                    ;% UAM_Flight_control_P.RollController_LowerSaturationL
                    section.data(67).logicalSrcIdx = 76;
                    section.data(67).dtTransOffset = 66;

                    ;% UAM_Flight_control_P.RollRateController_LowerSatur_o
                    section.data(68).logicalSrcIdx = 77;
                    section.data(68).dtTransOffset = 67;

                    ;% UAM_Flight_control_P.PitchAngleController_LowerSat_e
                    section.data(69).logicalSrcIdx = 78;
                    section.data(69).dtTransOffset = 68;

                    ;% UAM_Flight_control_P.PitchRateController_LowerSatu_o
                    section.data(70).logicalSrcIdx = 79;
                    section.data(70).dtTransOffset = 69;

                    ;% UAM_Flight_control_P.RudderController_LowerSaturat_f
                    section.data(71).logicalSrcIdx = 80;
                    section.data(71).dtTransOffset = 70;

                    ;% UAM_Flight_control_P.RollRateController_LowerSatur_g
                    section.data(72).logicalSrcIdx = 81;
                    section.data(72).dtTransOffset = 71;

                    ;% UAM_Flight_control_P.RudderController_P
                    section.data(73).logicalSrcIdx = 82;
                    section.data(73).dtTransOffset = 72;

                    ;% UAM_Flight_control_P.Altitudecontroller_P
                    section.data(74).logicalSrcIdx = 83;
                    section.data(74).dtTransOffset = 73;

                    ;% UAM_Flight_control_P.RudderController_P_a
                    section.data(75).logicalSrcIdx = 84;
                    section.data(75).dtTransOffset = 74;

                    ;% UAM_Flight_control_P.PitchRateController_P
                    section.data(76).logicalSrcIdx = 85;
                    section.data(76).dtTransOffset = 75;

                    ;% UAM_Flight_control_P.RudderController_P_f
                    section.data(77).logicalSrcIdx = 86;
                    section.data(77).dtTransOffset = 76;

                    ;% UAM_Flight_control_P.RollController_P
                    section.data(78).logicalSrcIdx = 87;
                    section.data(78).dtTransOffset = 77;

                    ;% UAM_Flight_control_P.PitchController_P
                    section.data(79).logicalSrcIdx = 88;
                    section.data(79).dtTransOffset = 78;

                    ;% UAM_Flight_control_P.Yawratecontroller_P
                    section.data(80).logicalSrcIdx = 89;
                    section.data(80).dtTransOffset = 79;

                    ;% UAM_Flight_control_P.Altituderatecontroller_UpperInt
                    section.data(81).logicalSrcIdx = 90;
                    section.data(81).dtTransOffset = 80;

                    ;% UAM_Flight_control_P.Lateralvelocitycontroller_Upper
                    section.data(82).logicalSrcIdx = 91;
                    section.data(82).dtTransOffset = 81;

                    ;% UAM_Flight_control_P.Forwardvelocitycontroller_Upper
                    section.data(83).logicalSrcIdx = 92;
                    section.data(83).dtTransOffset = 82;

                    ;% UAM_Flight_control_P.Yawratecontroller_UpperIntegrat
                    section.data(84).logicalSrcIdx = 93;
                    section.data(84).dtTransOffset = 83;

                    ;% UAM_Flight_control_P.Pitchratecontroller_UpperIntegr
                    section.data(85).logicalSrcIdx = 94;
                    section.data(85).dtTransOffset = 84;

                    ;% UAM_Flight_control_P.Rollratecontroller_UpperIntegra
                    section.data(86).logicalSrcIdx = 95;
                    section.data(86).dtTransOffset = 85;

                    ;% UAM_Flight_control_P.Altituderatecontroller_UpperI_n
                    section.data(87).logicalSrcIdx = 96;
                    section.data(87).dtTransOffset = 86;

                    ;% UAM_Flight_control_P.Forwardvelocitycontroller_Upp_k
                    section.data(88).logicalSrcIdx = 97;
                    section.data(88).dtTransOffset = 87;

                    ;% UAM_Flight_control_P.Lateralvelocitycontroller_Upp_g
                    section.data(89).logicalSrcIdx = 98;
                    section.data(89).dtTransOffset = 88;

                    ;% UAM_Flight_control_P.Yawratecontroller_UpperIntegr_o
                    section.data(90).logicalSrcIdx = 99;
                    section.data(90).dtTransOffset = 89;

                    ;% UAM_Flight_control_P.PitchRateController_UpperIntegr
                    section.data(91).logicalSrcIdx = 100;
                    section.data(91).dtTransOffset = 90;

                    ;% UAM_Flight_control_P.RollRateController_UpperIntegra
                    section.data(92).logicalSrcIdx = 101;
                    section.data(92).dtTransOffset = 91;

                    ;% UAM_Flight_control_P.PitchAngleController_UpperSatur
                    section.data(93).logicalSrcIdx = 102;
                    section.data(93).dtTransOffset = 92;

                    ;% UAM_Flight_control_P.PitchRateController_UpperSatura
                    section.data(94).logicalSrcIdx = 103;
                    section.data(94).dtTransOffset = 93;

                    ;% UAM_Flight_control_P.RudderController_UpperSaturatio
                    section.data(95).logicalSrcIdx = 104;
                    section.data(95).dtTransOffset = 94;

                    ;% UAM_Flight_control_P.RollRateController_UpperSaturat
                    section.data(96).logicalSrcIdx = 105;
                    section.data(96).dtTransOffset = 95;

                    ;% UAM_Flight_control_P.Altituderatecontroller_UpperSat
                    section.data(97).logicalSrcIdx = 106;
                    section.data(97).dtTransOffset = 96;

                    ;% UAM_Flight_control_P.Lateralpositioncontroller_Upper
                    section.data(98).logicalSrcIdx = 107;
                    section.data(98).dtTransOffset = 97;

                    ;% UAM_Flight_control_P.Lateralvelocitycontroller_Upp_b
                    section.data(99).logicalSrcIdx = 108;
                    section.data(99).dtTransOffset = 98;

                    ;% UAM_Flight_control_P.Forwardvelocitycontroller_Upp_o
                    section.data(100).logicalSrcIdx = 109;
                    section.data(100).dtTransOffset = 99;

                    ;% UAM_Flight_control_P.RudderController_UpperSaturat_g
                    section.data(101).logicalSrcIdx = 110;
                    section.data(101).dtTransOffset = 100;

                    ;% UAM_Flight_control_P.PitchAngleController_UpperSat_j
                    section.data(102).logicalSrcIdx = 111;
                    section.data(102).dtTransOffset = 101;

                    ;% UAM_Flight_control_P.PitchRateController_UpperSatu_p
                    section.data(103).logicalSrcIdx = 112;
                    section.data(103).dtTransOffset = 102;

                    ;% UAM_Flight_control_P.RollRateController_UpperSatur_c
                    section.data(104).logicalSrcIdx = 113;
                    section.data(104).dtTransOffset = 103;

                    ;% UAM_Flight_control_P.Altitudecontroller_UpperSaturat
                    section.data(105).logicalSrcIdx = 114;
                    section.data(105).dtTransOffset = 104;

                    ;% UAM_Flight_control_P.Altituderatecontroller_UpperS_b
                    section.data(106).logicalSrcIdx = 115;
                    section.data(106).dtTransOffset = 105;

                    ;% UAM_Flight_control_P.Forwardpositioncontroller_Upper
                    section.data(107).logicalSrcIdx = 116;
                    section.data(107).dtTransOffset = 106;

                    ;% UAM_Flight_control_P.Lateralpositioncontroller_Upp_a
                    section.data(108).logicalSrcIdx = 117;
                    section.data(108).dtTransOffset = 107;

                    ;% UAM_Flight_control_P.Forwardvelocitycontroller_Upp_h
                    section.data(109).logicalSrcIdx = 118;
                    section.data(109).dtTransOffset = 108;

                    ;% UAM_Flight_control_P.Lateralvelocitycontroller_Upp_f
                    section.data(110).logicalSrcIdx = 119;
                    section.data(110).dtTransOffset = 109;

                    ;% UAM_Flight_control_P.Yawratecontroller_UpperSaturati
                    section.data(111).logicalSrcIdx = 120;
                    section.data(111).dtTransOffset = 110;

                    ;% UAM_Flight_control_P.PitchController_UpperSaturation
                    section.data(112).logicalSrcIdx = 121;
                    section.data(112).dtTransOffset = 111;

                    ;% UAM_Flight_control_P.PitchRateController_UpperSatu_h
                    section.data(113).logicalSrcIdx = 122;
                    section.data(113).dtTransOffset = 112;

                    ;% UAM_Flight_control_P.RollController_UpperSaturationL
                    section.data(114).logicalSrcIdx = 123;
                    section.data(114).dtTransOffset = 113;

                    ;% UAM_Flight_control_P.RollRateController_UpperSatu_c0
                    section.data(115).logicalSrcIdx = 124;
                    section.data(115).dtTransOffset = 114;

                    ;% UAM_Flight_control_P.PitchAngleController_UpperSat_c
                    section.data(116).logicalSrcIdx = 125;
                    section.data(116).dtTransOffset = 115;

                    ;% UAM_Flight_control_P.PitchRateController_UpperSatu_l
                    section.data(117).logicalSrcIdx = 126;
                    section.data(117).dtTransOffset = 116;

                    ;% UAM_Flight_control_P.RudderController_UpperSaturat_i
                    section.data(118).logicalSrcIdx = 127;
                    section.data(118).dtTransOffset = 117;

                    ;% UAM_Flight_control_P.RollRateController_UpperSatur_l
                    section.data(119).logicalSrcIdx = 128;
                    section.data(119).dtTransOffset = 118;

                    ;% UAM_Flight_control_P.CompareToConstant_const
                    section.data(120).logicalSrcIdx = 129;
                    section.data(120).dtTransOffset = 119;

                    ;% UAM_Flight_control_P.CompareToConstant_const_i
                    section.data(121).logicalSrcIdx = 130;
                    section.data(121).dtTransOffset = 120;

                    ;% UAM_Flight_control_P.CompareToConstant1_const
                    section.data(122).logicalSrcIdx = 131;
                    section.data(122).dtTransOffset = 121;

                    ;% UAM_Flight_control_P.deadzone_const
                    section.data(123).logicalSrcIdx = 132;
                    section.data(123).dtTransOffset = 122;

                    ;% UAM_Flight_control_P.disarm_const
                    section.data(124).logicalSrcIdx = 133;
                    section.data(124).dtTransOffset = 123;

                    ;% UAM_Flight_control_P.arm_const
                    section.data(125).logicalSrcIdx = 134;
                    section.data(125).dtTransOffset = 124;

                    ;% UAM_Flight_control_P.CompareToConstant_const_k
                    section.data(126).logicalSrcIdx = 135;
                    section.data(126).dtTransOffset = 125;

                    ;% UAM_Flight_control_P.CompareToConstant_const_k3
                    section.data(127).logicalSrcIdx = 136;
                    section.data(127).dtTransOffset = 126;

                    ;% UAM_Flight_control_P.CompareToConstant1_const_f
                    section.data(128).logicalSrcIdx = 137;
                    section.data(128).dtTransOffset = 127;

                    ;% UAM_Flight_control_P.CompareToConstant_const_g
                    section.data(129).logicalSrcIdx = 138;
                    section.data(129).dtTransOffset = 128;

                    ;% UAM_Flight_control_P.CompareToConstant_const_b
                    section.data(130).logicalSrcIdx = 139;
                    section.data(130).dtTransOffset = 129;

                    ;% UAM_Flight_control_P.CompareToConstant_const_d
                    section.data(131).logicalSrcIdx = 140;
                    section.data(131).dtTransOffset = 130;

            nTotData = nTotData + section.nData;
            paramMap.sections(7) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.DetectRisePositive_vinit
                    section.data(1).logicalSrcIdx = 141;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_P.DetectRisePositive1_vinit
                    section.data(2).logicalSrcIdx = 142;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_P.DetectRisePositive_vinit_j
                    section.data(3).logicalSrcIdx = 143;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_P.DetectRisePositive1_vinit_g
                    section.data(4).logicalSrcIdx = 144;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            paramMap.sections(8) = section;
            clear section

            section.nData     = 10;
            section.data(10)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.CompareToConstant_const_a
                    section.data(1).logicalSrcIdx = 145;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_P.prev_is_1_const
                    section.data(2).logicalSrcIdx = 146;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_P.now_is_0_const
                    section.data(3).logicalSrcIdx = 147;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_P.CompareToConstant_const_p
                    section.data(4).logicalSrcIdx = 148;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_P.CompareToConstant1_const_c
                    section.data(5).logicalSrcIdx = 149;
                    section.data(5).dtTransOffset = 4;

                    ;% UAM_Flight_control_P.CompareToConstant_const_m
                    section.data(6).logicalSrcIdx = 150;
                    section.data(6).dtTransOffset = 5;

                    ;% UAM_Flight_control_P.CompareToConstant1_const_k
                    section.data(7).logicalSrcIdx = 151;
                    section.data(7).dtTransOffset = 6;

                    ;% UAM_Flight_control_P.CompareToConstant_const_e
                    section.data(8).logicalSrcIdx = 152;
                    section.data(8).dtTransOffset = 7;

                    ;% UAM_Flight_control_P.CompareToConstant_const_ko
                    section.data(9).logicalSrcIdx = 153;
                    section.data(9).dtTransOffset = 8;

                    ;% UAM_Flight_control_P.CompareToConstant_const_c
                    section.data(10).logicalSrcIdx = 154;
                    section.data(10).dtTransOffset = 9;

            nTotData = nTotData + section.nData;
            paramMap.sections(9) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.UnitDelay_3_InitialCondition
                    section.data(1).logicalSrcIdx = 155;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(10) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.UnitDelay_2_InitialCondition
                    section.data(1).logicalSrcIdx = 156;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(11) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Waypoints2_Value
                    section.data(1).logicalSrcIdx = 157;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(12) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Merge_2_InitialOutput
                    section.data(1).logicalSrcIdx = 158;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(13) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Merge_3_InitialOutput
                    section.data(1).logicalSrcIdx = 159;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(14) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.UnitDelay_6_InitialCondition
                    section.data(1).logicalSrcIdx = 160;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(15) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Constant2_Value
                    section.data(1).logicalSrcIdx = 161;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(16) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.UnitDelay_6_InitialCondition_d
                    section.data(1).logicalSrcIdx = 162;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(17) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.UnitDelay_6_InitialCondition_l
                    section.data(1).logicalSrcIdx = 163;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(18) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Constant2_Value_i
                    section.data(1).logicalSrcIdx = 164;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(19) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Merge_6_InitialOutput
                    section.data(1).logicalSrcIdx = 165;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(20) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.UnitDelay1_7_InitialCondition
                    section.data(1).logicalSrcIdx = 166;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(21) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Merge_10_InitialOutput
                    section.data(1).logicalSrcIdx = 167;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(22) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.UnitDelay_7_InitialCondition
                    section.data(1).logicalSrcIdx = 168;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(23) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.UnitDelay_7_InitialCondition_d
                    section.data(1).logicalSrcIdx = 169;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(24) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.UnitDelay_7_InitialCondition_l
                    section.data(1).logicalSrcIdx = 170;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(25) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Merge_7_InitialOutput
                    section.data(1).logicalSrcIdx = 171;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(26) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.MixerCommands_Y0
                    section.data(1).logicalSrcIdx = 172;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(27) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.MixerCommands_Y0_o
                    section.data(1).logicalSrcIdx = 173;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(28) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.MixerCommands_Y0_e
                    section.data(1).logicalSrcIdx = 174;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(29) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Actuator_Outport_1_Y0
                    section.data(1).logicalSrcIdx = 175;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(30) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Actuator_Outport_1_Y0_d
                    section.data(1).logicalSrcIdx = 176;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(31) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Actuator_Outport_1_Y0_d1
                    section.data(1).logicalSrcIdx = 177;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(32) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Actuator_Outport_1_Y0_d1t
                    section.data(1).logicalSrcIdx = 178;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(33) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.UnitDelay_5_InitialCondition
                    section.data(1).logicalSrcIdx = 179;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(34) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Constant1_Value
                    section.data(1).logicalSrcIdx = 180;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(35) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.UnitDelay_5_InitialCondition_d
                    section.data(1).logicalSrcIdx = 181;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(36) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.UnitDelay_5_InitialCondition_l
                    section.data(1).logicalSrcIdx = 182;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(37) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Constant1_Value_f
                    section.data(1).logicalSrcIdx = 183;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(38) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Merge_5_InitialOutput
                    section.data(1).logicalSrcIdx = 184;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(39) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.CtrlSurfaceCommands_Y0
                    section.data(1).logicalSrcIdx = 185;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(40) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Merge_InitialOutput
                    section.data(1).logicalSrcIdx = 186;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(41) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.CtrlSurfaceCommands_Y0_h
                    section.data(1).logicalSrcIdx = 187;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(42) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Merge_InitialOutput_m
                    section.data(1).logicalSrcIdx = 188;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(43) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.CtrlSurfaceCommands_Y0_k
                    section.data(1).logicalSrcIdx = 189;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(44) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Merge_InitialOutput_g
                    section.data(1).logicalSrcIdx = 190;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(45) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Merge_68_InitialOutput
                    section.data(1).logicalSrcIdx = 191;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(46) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Actuator_Y0
                    section.data(1).logicalSrcIdx = 192;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(47) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Actuator_Y0_a
                    section.data(1).logicalSrcIdx = 193;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(48) = section;
            clear section

            section.nData     = 495;
            section.data(495)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.AER_Y0
                    section.data(1).logicalSrcIdx = 194;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_P.Constant1_Value_l
                    section.data(2).logicalSrcIdx = 195;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_P.Constant_Value
                    section.data(3).logicalSrcIdx = 196;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_P.Integrator_gainval
                    section.data(4).logicalSrcIdx = 197;
                    section.data(4).dtTransOffset = 6;

                    ;% UAM_Flight_control_P.Filter_gainval
                    section.data(5).logicalSrcIdx = 198;
                    section.data(5).dtTransOffset = 7;

                    ;% UAM_Flight_control_P.Saturation2_UpperSat
                    section.data(6).logicalSrcIdx = 199;
                    section.data(6).dtTransOffset = 8;

                    ;% UAM_Flight_control_P.Saturation2_LowerSat
                    section.data(7).logicalSrcIdx = 200;
                    section.data(7).dtTransOffset = 9;

                    ;% UAM_Flight_control_P.Clamping_zero_Value
                    section.data(8).logicalSrcIdx = 201;
                    section.data(8).dtTransOffset = 10;

                    ;% UAM_Flight_control_P.Bias_Bias
                    section.data(9).logicalSrcIdx = 202;
                    section.data(9).dtTransOffset = 11;

                    ;% UAM_Flight_control_P.Gain_Gain
                    section.data(10).logicalSrcIdx = 203;
                    section.data(10).dtTransOffset = 12;

                    ;% UAM_Flight_control_P.Gain1_Gain
                    section.data(11).logicalSrcIdx = 204;
                    section.data(11).dtTransOffset = 13;

                    ;% UAM_Flight_control_P.Bias_Bias_k
                    section.data(12).logicalSrcIdx = 205;
                    section.data(12).dtTransOffset = 14;

                    ;% UAM_Flight_control_P.Gain_Gain_g
                    section.data(13).logicalSrcIdx = 206;
                    section.data(13).dtTransOffset = 15;

                    ;% UAM_Flight_control_P.Gain1_Gain_d
                    section.data(14).logicalSrcIdx = 207;
                    section.data(14).dtTransOffset = 16;

                    ;% UAM_Flight_control_P.Constant_Value_m
                    section.data(15).logicalSrcIdx = 208;
                    section.data(15).dtTransOffset = 17;

                    ;% UAM_Flight_control_P.Constant4_Value
                    section.data(16).logicalSrcIdx = 209;
                    section.data(16).dtTransOffset = 33;

                    ;% UAM_Flight_control_P.MotorActuatorCommands_Y0
                    section.data(17).logicalSrcIdx = 210;
                    section.data(17).dtTransOffset = 34;

                    ;% UAM_Flight_control_P.Gain1_Gain_e
                    section.data(18).logicalSrcIdx = 211;
                    section.data(18).dtTransOffset = 35;

                    ;% UAM_Flight_control_P.Constant2_Value_j
                    section.data(19).logicalSrcIdx = 212;
                    section.data(19).dtTransOffset = 36;

                    ;% UAM_Flight_control_P.Gain3_Gain
                    section.data(20).logicalSrcIdx = 213;
                    section.data(20).dtTransOffset = 37;

                    ;% UAM_Flight_control_P.Constant4_Value_i
                    section.data(21).logicalSrcIdx = 214;
                    section.data(21).dtTransOffset = 38;

                    ;% UAM_Flight_control_P.Gain5_Gain
                    section.data(22).logicalSrcIdx = 215;
                    section.data(22).dtTransOffset = 39;

                    ;% UAM_Flight_control_P.Constant6_Value
                    section.data(23).logicalSrcIdx = 216;
                    section.data(23).dtTransOffset = 40;

                    ;% UAM_Flight_control_P.Gain7_Gain
                    section.data(24).logicalSrcIdx = 217;
                    section.data(24).dtTransOffset = 41;

                    ;% UAM_Flight_control_P.Constant8_Value
                    section.data(25).logicalSrcIdx = 218;
                    section.data(25).dtTransOffset = 42;

                    ;% UAM_Flight_control_P.Constant_Value_d
                    section.data(26).logicalSrcIdx = 219;
                    section.data(26).dtTransOffset = 43;

                    ;% UAM_Flight_control_P.Saturation_UpperSat
                    section.data(27).logicalSrcIdx = 220;
                    section.data(27).dtTransOffset = 44;

                    ;% UAM_Flight_control_P.Saturation_LowerSat
                    section.data(28).logicalSrcIdx = 221;
                    section.data(28).dtTransOffset = 45;

                    ;% UAM_Flight_control_P.Saturation1_UpperSat
                    section.data(29).logicalSrcIdx = 222;
                    section.data(29).dtTransOffset = 46;

                    ;% UAM_Flight_control_P.Saturation1_LowerSat
                    section.data(30).logicalSrcIdx = 223;
                    section.data(30).dtTransOffset = 47;

                    ;% UAM_Flight_control_P.Saturation2_UpperSat_b
                    section.data(31).logicalSrcIdx = 224;
                    section.data(31).dtTransOffset = 48;

                    ;% UAM_Flight_control_P.Saturation2_LowerSat_n
                    section.data(32).logicalSrcIdx = 225;
                    section.data(32).dtTransOffset = 49;

                    ;% UAM_Flight_control_P.Saturation3_UpperSat
                    section.data(33).logicalSrcIdx = 226;
                    section.data(33).dtTransOffset = 50;

                    ;% UAM_Flight_control_P.Saturation3_LowerSat
                    section.data(34).logicalSrcIdx = 227;
                    section.data(34).dtTransOffset = 51;

                    ;% UAM_Flight_control_P.Saturation4_UpperSat
                    section.data(35).logicalSrcIdx = 228;
                    section.data(35).dtTransOffset = 52;

                    ;% UAM_Flight_control_P.Saturation4_LowerSat
                    section.data(36).logicalSrcIdx = 229;
                    section.data(36).dtTransOffset = 53;

                    ;% UAM_Flight_control_P.throttle_up_Gain
                    section.data(37).logicalSrcIdx = 230;
                    section.data(37).dtTransOffset = 54;

                    ;% UAM_Flight_control_P.throttle_down_Gain
                    section.data(38).logicalSrcIdx = 231;
                    section.data(38).dtTransOffset = 55;

                    ;% UAM_Flight_control_P.Switch_Threshold
                    section.data(39).logicalSrcIdx = 232;
                    section.data(39).dtTransOffset = 56;

                    ;% UAM_Flight_control_P.Constant1_Value_p
                    section.data(40).logicalSrcIdx = 233;
                    section.data(40).dtTransOffset = 57;

                    ;% UAM_Flight_control_P.Gain_Gain_b
                    section.data(41).logicalSrcIdx = 234;
                    section.data(41).dtTransOffset = 58;

                    ;% UAM_Flight_control_P.Bias_Bias_h
                    section.data(42).logicalSrcIdx = 235;
                    section.data(42).dtTransOffset = 59;

                    ;% UAM_Flight_control_P.Gain3_Gain_h
                    section.data(43).logicalSrcIdx = 236;
                    section.data(43).dtTransOffset = 60;

                    ;% UAM_Flight_control_P.DeadZone_Start
                    section.data(44).logicalSrcIdx = 237;
                    section.data(44).dtTransOffset = 61;

                    ;% UAM_Flight_control_P.DeadZone_End
                    section.data(45).logicalSrcIdx = 238;
                    section.data(45).dtTransOffset = 62;

                    ;% UAM_Flight_control_P.Constant_Value_o
                    section.data(46).logicalSrcIdx = 239;
                    section.data(46).dtTransOffset = 63;

                    ;% UAM_Flight_control_P.UnitDelay_InitialCondition
                    section.data(47).logicalSrcIdx = 240;
                    section.data(47).dtTransOffset = 64;

                    ;% UAM_Flight_control_P.Gain1_Gain_p
                    section.data(48).logicalSrcIdx = 241;
                    section.data(48).dtTransOffset = 65;

                    ;% UAM_Flight_control_P.Integrator_gainval_n
                    section.data(49).logicalSrcIdx = 242;
                    section.data(49).dtTransOffset = 66;

                    ;% UAM_Flight_control_P.Filter_gainval_e
                    section.data(50).logicalSrcIdx = 243;
                    section.data(50).dtTransOffset = 67;

                    ;% UAM_Flight_control_P.UnitDelay_InitialCondition_k
                    section.data(51).logicalSrcIdx = 244;
                    section.data(51).dtTransOffset = 68;

                    ;% UAM_Flight_control_P.hover_thrustg_Gain
                    section.data(52).logicalSrcIdx = 245;
                    section.data(52).dtTransOffset = 69;

                    ;% UAM_Flight_control_P.Saturation1_UpperSat_p
                    section.data(53).logicalSrcIdx = 246;
                    section.data(53).dtTransOffset = 70;

                    ;% UAM_Flight_control_P.Saturation1_LowerSat_i
                    section.data(54).logicalSrcIdx = 247;
                    section.data(54).dtTransOffset = 71;

                    ;% UAM_Flight_control_P.Clamping_zero_Value_n
                    section.data(55).logicalSrcIdx = 248;
                    section.data(55).dtTransOffset = 72;

                    ;% UAM_Flight_control_P.yaw_max_rate_Gain
                    section.data(56).logicalSrcIdx = 249;
                    section.data(56).dtTransOffset = 73;

                    ;% UAM_Flight_control_P.FowardVelocitySetpoint_UpperSat
                    section.data(57).logicalSrcIdx = 250;
                    section.data(57).dtTransOffset = 74;

                    ;% UAM_Flight_control_P.FowardVelocitySetpoint_LowerSat
                    section.data(58).logicalSrcIdx = 251;
                    section.data(58).dtTransOffset = 75;

                    ;% UAM_Flight_control_P.Vel_manual_Gain
                    section.data(59).logicalSrcIdx = 252;
                    section.data(59).dtTransOffset = 76;

                    ;% UAM_Flight_control_P.LateralVelocitySetpoint_UpperSa
                    section.data(60).logicalSrcIdx = 253;
                    section.data(60).dtTransOffset = 77;

                    ;% UAM_Flight_control_P.LateralVelocitySetpoint_LowerSa
                    section.data(61).logicalSrcIdx = 254;
                    section.data(61).dtTransOffset = 78;

                    ;% UAM_Flight_control_P.Vel_manualms_Gain
                    section.data(62).logicalSrcIdx = 255;
                    section.data(62).dtTransOffset = 79;

                    ;% UAM_Flight_control_P.Constant1_Value_g
                    section.data(63).logicalSrcIdx = 256;
                    section.data(63).dtTransOffset = 80;

                    ;% UAM_Flight_control_P.Constant1_Value_h
                    section.data(64).logicalSrcIdx = 257;
                    section.data(64).dtTransOffset = 81;

                    ;% UAM_Flight_control_P.Gain_Gain_i
                    section.data(65).logicalSrcIdx = 258;
                    section.data(65).dtTransOffset = 82;

                    ;% UAM_Flight_control_P.DeadZone_Start_b
                    section.data(66).logicalSrcIdx = 259;
                    section.data(66).dtTransOffset = 83;

                    ;% UAM_Flight_control_P.DeadZone_End_h
                    section.data(67).logicalSrcIdx = 260;
                    section.data(67).dtTransOffset = 84;

                    ;% UAM_Flight_control_P.Constant_Value_k
                    section.data(68).logicalSrcIdx = 261;
                    section.data(68).dtTransOffset = 85;

                    ;% UAM_Flight_control_P.DeadZone1_Start
                    section.data(69).logicalSrcIdx = 262;
                    section.data(69).dtTransOffset = 86;

                    ;% UAM_Flight_control_P.DeadZone1_End
                    section.data(70).logicalSrcIdx = 263;
                    section.data(70).dtTransOffset = 87;

                    ;% UAM_Flight_control_P.Constant1_Value_o
                    section.data(71).logicalSrcIdx = 264;
                    section.data(71).dtTransOffset = 88;

                    ;% UAM_Flight_control_P.UnitDelay_InitialCondition_o
                    section.data(72).logicalSrcIdx = 265;
                    section.data(72).dtTransOffset = 89;

                    ;% UAM_Flight_control_P.Gain_Gain_i2
                    section.data(73).logicalSrcIdx = 266;
                    section.data(73).dtTransOffset = 90;

                    ;% UAM_Flight_control_P.UnitDelay1_InitialCondition
                    section.data(74).logicalSrcIdx = 267;
                    section.data(74).dtTransOffset = 91;

                    ;% UAM_Flight_control_P.Constant2_Value_n
                    section.data(75).logicalSrcIdx = 268;
                    section.data(75).dtTransOffset = 92;

                    ;% UAM_Flight_control_P.RateLimiter_RisingLim
                    section.data(76).logicalSrcIdx = 269;
                    section.data(76).dtTransOffset = 93;

                    ;% UAM_Flight_control_P.RateLimiter_FallingLim
                    section.data(77).logicalSrcIdx = 270;
                    section.data(77).dtTransOffset = 94;

                    ;% UAM_Flight_control_P.RateLimiter_IC
                    section.data(78).logicalSrcIdx = 271;
                    section.data(78).dtTransOffset = 95;

                    ;% UAM_Flight_control_P.Integrator_gainval_d
                    section.data(79).logicalSrcIdx = 272;
                    section.data(79).dtTransOffset = 96;

                    ;% UAM_Flight_control_P.Filter_gainval_i
                    section.data(80).logicalSrcIdx = 273;
                    section.data(80).dtTransOffset = 97;

                    ;% UAM_Flight_control_P.Clamping_zero_Value_b
                    section.data(81).logicalSrcIdx = 274;
                    section.data(81).dtTransOffset = 98;

                    ;% UAM_Flight_control_P.rad_Gain
                    section.data(82).logicalSrcIdx = 275;
                    section.data(82).dtTransOffset = 99;

                    ;% UAM_Flight_control_P.Saturation1_UpperSat_a
                    section.data(83).logicalSrcIdx = 276;
                    section.data(83).dtTransOffset = 100;

                    ;% UAM_Flight_control_P.Saturation1_LowerSat_m
                    section.data(84).logicalSrcIdx = 277;
                    section.data(84).dtTransOffset = 101;

                    ;% UAM_Flight_control_P.RateLimiter1_RisingLim
                    section.data(85).logicalSrcIdx = 278;
                    section.data(85).dtTransOffset = 102;

                    ;% UAM_Flight_control_P.RateLimiter1_FallingLim
                    section.data(86).logicalSrcIdx = 279;
                    section.data(86).dtTransOffset = 103;

                    ;% UAM_Flight_control_P.RateLimiter1_IC
                    section.data(87).logicalSrcIdx = 280;
                    section.data(87).dtTransOffset = 104;

                    ;% UAM_Flight_control_P.Integrator_gainval_i
                    section.data(88).logicalSrcIdx = 281;
                    section.data(88).dtTransOffset = 105;

                    ;% UAM_Flight_control_P.Filter_gainval_j
                    section.data(89).logicalSrcIdx = 282;
                    section.data(89).dtTransOffset = 106;

                    ;% UAM_Flight_control_P.Clamping_zero_Value_p
                    section.data(90).logicalSrcIdx = 283;
                    section.data(90).dtTransOffset = 107;

                    ;% UAM_Flight_control_P.Gain_Gain_j
                    section.data(91).logicalSrcIdx = 284;
                    section.data(91).dtTransOffset = 108;

                    ;% UAM_Flight_control_P.Saturation_UpperSat_e
                    section.data(92).logicalSrcIdx = 285;
                    section.data(92).dtTransOffset = 109;

                    ;% UAM_Flight_control_P.Saturation_LowerSat_f
                    section.data(93).logicalSrcIdx = 286;
                    section.data(93).dtTransOffset = 110;

                    ;% UAM_Flight_control_P.Bias1_Bias
                    section.data(94).logicalSrcIdx = 287;
                    section.data(94).dtTransOffset = 111;

                    ;% UAM_Flight_control_P.Gain1_Gain_k
                    section.data(95).logicalSrcIdx = 288;
                    section.data(95).dtTransOffset = 112;

                    ;% UAM_Flight_control_P.Saturation_UpperSat_f
                    section.data(96).logicalSrcIdx = 289;
                    section.data(96).dtTransOffset = 113;

                    ;% UAM_Flight_control_P.Saturation_LowerSat_e
                    section.data(97).logicalSrcIdx = 290;
                    section.data(97).dtTransOffset = 114;

                    ;% UAM_Flight_control_P.Merge2_InitialOutput
                    section.data(98).logicalSrcIdx = 291;
                    section.data(98).dtTransOffset = 115;

                    ;% UAM_Flight_control_P.Bias_Bias_j
                    section.data(99).logicalSrcIdx = 292;
                    section.data(99).dtTransOffset = 116;

                    ;% UAM_Flight_control_P.Gain_Gain_c
                    section.data(100).logicalSrcIdx = 293;
                    section.data(100).dtTransOffset = 117;

                    ;% UAM_Flight_control_P.RefRP_InitialOutput
                    section.data(101).logicalSrcIdx = 294;
                    section.data(101).dtTransOffset = 118;

                    ;% UAM_Flight_control_P.UnitDelay1_InitialCondition_p
                    section.data(102).logicalSrcIdx = 295;
                    section.data(102).dtTransOffset = 119;

                    ;% UAM_Flight_control_P.Integrator_gainval_du
                    section.data(103).logicalSrcIdx = 296;
                    section.data(103).dtTransOffset = 120;

                    ;% UAM_Flight_control_P.Gain1_Gain_k5
                    section.data(104).logicalSrcIdx = 297;
                    section.data(104).dtTransOffset = 121;

                    ;% UAM_Flight_control_P.Pitch_MAX_angle_Gain
                    section.data(105).logicalSrcIdx = 298;
                    section.data(105).dtTransOffset = 122;

                    ;% UAM_Flight_control_P.Saturation1_UpperSat_g
                    section.data(106).logicalSrcIdx = 299;
                    section.data(106).dtTransOffset = 123;

                    ;% UAM_Flight_control_P.Saturation1_LowerSat_b
                    section.data(107).logicalSrcIdx = 300;
                    section.data(107).dtTransOffset = 124;

                    ;% UAM_Flight_control_P.Filter_gainval_p
                    section.data(108).logicalSrcIdx = 301;
                    section.data(108).dtTransOffset = 125;

                    ;% UAM_Flight_control_P.Integrator_gainval_m
                    section.data(109).logicalSrcIdx = 302;
                    section.data(109).dtTransOffset = 126;

                    ;% UAM_Flight_control_P.Roll_MAX_angle_Gain
                    section.data(110).logicalSrcIdx = 303;
                    section.data(110).dtTransOffset = 127;

                    ;% UAM_Flight_control_P.Saturation_UpperSat_d
                    section.data(111).logicalSrcIdx = 304;
                    section.data(111).dtTransOffset = 128;

                    ;% UAM_Flight_control_P.Saturation_LowerSat_p
                    section.data(112).logicalSrcIdx = 305;
                    section.data(112).dtTransOffset = 129;

                    ;% UAM_Flight_control_P.Filter_gainval_c
                    section.data(113).logicalSrcIdx = 306;
                    section.data(113).dtTransOffset = 130;

                    ;% UAM_Flight_control_P.Integrator_gainval_o
                    section.data(114).logicalSrcIdx = 307;
                    section.data(114).dtTransOffset = 131;

                    ;% UAM_Flight_control_P.Saturation5_UpperSat
                    section.data(115).logicalSrcIdx = 308;
                    section.data(115).dtTransOffset = 132;

                    ;% UAM_Flight_control_P.Saturation5_LowerSat
                    section.data(116).logicalSrcIdx = 309;
                    section.data(116).dtTransOffset = 133;

                    ;% UAM_Flight_control_P.Saturation_UpperSat_n
                    section.data(117).logicalSrcIdx = 310;
                    section.data(117).dtTransOffset = 134;

                    ;% UAM_Flight_control_P.Saturation_LowerSat_b
                    section.data(118).logicalSrcIdx = 311;
                    section.data(118).dtTransOffset = 135;

                    ;% UAM_Flight_control_P.Constant6_Value_h
                    section.data(119).logicalSrcIdx = 312;
                    section.data(119).dtTransOffset = 136;

                    ;% UAM_Flight_control_P.Constant5_Value
                    section.data(120).logicalSrcIdx = 313;
                    section.data(120).dtTransOffset = 137;

                    ;% UAM_Flight_control_P.Gain3_Gain_l
                    section.data(121).logicalSrcIdx = 314;
                    section.data(121).dtTransOffset = 138;

                    ;% UAM_Flight_control_P.Constant3_Value
                    section.data(122).logicalSrcIdx = 315;
                    section.data(122).dtTransOffset = 139;

                    ;% UAM_Flight_control_P.Saturation1_UpperSat_f
                    section.data(123).logicalSrcIdx = 316;
                    section.data(123).dtTransOffset = 140;

                    ;% UAM_Flight_control_P.Saturation1_LowerSat_a
                    section.data(124).logicalSrcIdx = 317;
                    section.data(124).dtTransOffset = 141;

                    ;% UAM_Flight_control_P.Gain3_Gain_g
                    section.data(125).logicalSrcIdx = 318;
                    section.data(125).dtTransOffset = 142;

                    ;% UAM_Flight_control_P.Constant_Value_g
                    section.data(126).logicalSrcIdx = 319;
                    section.data(126).dtTransOffset = 143;

                    ;% UAM_Flight_control_P.Gain_Gain_k
                    section.data(127).logicalSrcIdx = 320;
                    section.data(127).dtTransOffset = 144;

                    ;% UAM_Flight_control_P.Saturation_UpperSat_i
                    section.data(128).logicalSrcIdx = 321;
                    section.data(128).dtTransOffset = 145;

                    ;% UAM_Flight_control_P.Saturation_LowerSat_l
                    section.data(129).logicalSrcIdx = 322;
                    section.data(129).dtTransOffset = 146;

                    ;% UAM_Flight_control_P.ClimbRateSPMerge_InitialOutput
                    section.data(130).logicalSrcIdx = 323;
                    section.data(130).dtTransOffset = 147;

                    ;% UAM_Flight_control_P.Gain_Gain_js
                    section.data(131).logicalSrcIdx = 324;
                    section.data(131).dtTransOffset = 148;

                    ;% UAM_Flight_control_P.Filter_gainval_l
                    section.data(132).logicalSrcIdx = 325;
                    section.data(132).dtTransOffset = 149;

                    ;% UAM_Flight_control_P.Integrator_gainval_j
                    section.data(133).logicalSrcIdx = 326;
                    section.data(133).dtTransOffset = 150;

                    ;% UAM_Flight_control_P.Constant1_Value_le
                    section.data(134).logicalSrcIdx = 327;
                    section.data(134).dtTransOffset = 151;

                    ;% UAM_Flight_control_P.Integrator_gainval_k
                    section.data(135).logicalSrcIdx = 328;
                    section.data(135).dtTransOffset = 152;

                    ;% UAM_Flight_control_P.Filter_gainval_o
                    section.data(136).logicalSrcIdx = 329;
                    section.data(136).dtTransOffset = 153;

                    ;% UAM_Flight_control_P.Gain2_Gain
                    section.data(137).logicalSrcIdx = 330;
                    section.data(137).dtTransOffset = 154;

                    ;% UAM_Flight_control_P.Gain1_Gain_m
                    section.data(138).logicalSrcIdx = 331;
                    section.data(138).dtTransOffset = 155;

                    ;% UAM_Flight_control_P.Saturation2_UpperSat_p
                    section.data(139).logicalSrcIdx = 332;
                    section.data(139).dtTransOffset = 156;

                    ;% UAM_Flight_control_P.Saturation2_LowerSat_e
                    section.data(140).logicalSrcIdx = 333;
                    section.data(140).dtTransOffset = 157;

                    ;% UAM_Flight_control_P.Clamping_zero_Value_ba
                    section.data(141).logicalSrcIdx = 334;
                    section.data(141).dtTransOffset = 158;

                    ;% UAM_Flight_control_P.Constant_Value_c
                    section.data(142).logicalSrcIdx = 335;
                    section.data(142).dtTransOffset = 159;

                    ;% UAM_Flight_control_P.Constant1_Value_k
                    section.data(143).logicalSrcIdx = 336;
                    section.data(143).dtTransOffset = 160;

                    ;% UAM_Flight_control_P.Filter_gainval_g
                    section.data(144).logicalSrcIdx = 337;
                    section.data(144).dtTransOffset = 161;

                    ;% UAM_Flight_control_P.Integrator_gainval_l
                    section.data(145).logicalSrcIdx = 338;
                    section.data(145).dtTransOffset = 162;

                    ;% UAM_Flight_control_P.IC_Value
                    section.data(146).logicalSrcIdx = 339;
                    section.data(146).dtTransOffset = 163;

                    ;% UAM_Flight_control_P.PitchSPMerge_InitialOutput
                    section.data(147).logicalSrcIdx = 340;
                    section.data(147).dtTransOffset = 164;

                    ;% UAM_Flight_control_P.RollSPMerge_InitialOutput
                    section.data(148).logicalSrcIdx = 341;
                    section.data(148).dtTransOffset = 165;

                    ;% UAM_Flight_control_P.ActuatordTMerge_InitialOutput
                    section.data(149).logicalSrcIdx = 342;
                    section.data(149).dtTransOffset = 166;

                    ;% UAM_Flight_control_P.Merge_InitialOutput_d
                    section.data(150).logicalSrcIdx = 343;
                    section.data(150).dtTransOffset = 167;

                    ;% UAM_Flight_control_P.Gain2_Gain_j
                    section.data(151).logicalSrcIdx = 344;
                    section.data(151).dtTransOffset = 168;

                    ;% UAM_Flight_control_P.Constant2_Value_l
                    section.data(152).logicalSrcIdx = 345;
                    section.data(152).dtTransOffset = 169;

                    ;% UAM_Flight_control_P.Reference_Y0
                    section.data(153).logicalSrcIdx = 346;
                    section.data(153).dtTransOffset = 170;

                    ;% UAM_Flight_control_P.commandedthrust_Y0
                    section.data(154).logicalSrcIdx = 347;
                    section.data(154).dtTransOffset = 171;

                    ;% UAM_Flight_control_P.Constant1_Value_j
                    section.data(155).logicalSrcIdx = 348;
                    section.data(155).dtTransOffset = 172;

                    ;% UAM_Flight_control_P.Gain1_Gain_h
                    section.data(156).logicalSrcIdx = 349;
                    section.data(156).dtTransOffset = 173;

                    ;% UAM_Flight_control_P.Constant1_Value_c
                    section.data(157).logicalSrcIdx = 350;
                    section.data(157).dtTransOffset = 174;

                    ;% UAM_Flight_control_P.Gain_Gain_h
                    section.data(158).logicalSrcIdx = 351;
                    section.data(158).dtTransOffset = 175;

                    ;% UAM_Flight_control_P.Clamping_zero_Value_g
                    section.data(159).logicalSrcIdx = 352;
                    section.data(159).dtTransOffset = 176;

                    ;% UAM_Flight_control_P.Integrator_gainval_p
                    section.data(160).logicalSrcIdx = 353;
                    section.data(160).dtTransOffset = 177;

                    ;% UAM_Flight_control_P.Filter_gainval_gk
                    section.data(161).logicalSrcIdx = 354;
                    section.data(161).dtTransOffset = 178;

                    ;% UAM_Flight_control_P.UnitDelay_InitialCondition_b
                    section.data(162).logicalSrcIdx = 355;
                    section.data(162).dtTransOffset = 179;

                    ;% UAM_Flight_control_P.hover_thrustg_Gain_m
                    section.data(163).logicalSrcIdx = 356;
                    section.data(163).dtTransOffset = 180;

                    ;% UAM_Flight_control_P.Saturation1_UpperSat_fd
                    section.data(164).logicalSrcIdx = 357;
                    section.data(164).dtTransOffset = 181;

                    ;% UAM_Flight_control_P.Saturation1_LowerSat_my
                    section.data(165).logicalSrcIdx = 358;
                    section.data(165).dtTransOffset = 182;

                    ;% UAM_Flight_control_P.Forwardcmd_Y0
                    section.data(166).logicalSrcIdx = 359;
                    section.data(166).dtTransOffset = 183;

                    ;% UAM_Flight_control_P.SidewardCmd_Y0
                    section.data(167).logicalSrcIdx = 360;
                    section.data(167).dtTransOffset = 184;

                    ;% UAM_Flight_control_P.Constant1_Value_i
                    section.data(168).logicalSrcIdx = 361;
                    section.data(168).dtTransOffset = 185;

                    ;% UAM_Flight_control_P.Constant1_Value_d
                    section.data(169).logicalSrcIdx = 362;
                    section.data(169).dtTransOffset = 186;

                    ;% UAM_Flight_control_P.Gain_Gain_f
                    section.data(170).logicalSrcIdx = 363;
                    section.data(170).dtTransOffset = 187;

                    ;% UAM_Flight_control_P.Value_Value
                    section.data(171).logicalSrcIdx = 364;
                    section.data(171).dtTransOffset = 188;

                    ;% UAM_Flight_control_P.MPC_ACC_HOR_Value
                    section.data(172).logicalSrcIdx = 365;
                    section.data(172).dtTransOffset = 189;

                    ;% UAM_Flight_control_P.Gain_Gain_a
                    section.data(173).logicalSrcIdx = 366;
                    section.data(173).dtTransOffset = 190;

                    ;% UAM_Flight_control_P.MPC_JERK_AUTO_Value
                    section.data(174).logicalSrcIdx = 367;
                    section.data(174).dtTransOffset = 191;

                    ;% UAM_Flight_control_P.Gain1_Gain_hd
                    section.data(175).logicalSrcIdx = 368;
                    section.data(175).dtTransOffset = 192;

                    ;% UAM_Flight_control_P.Gain2_Gain_a
                    section.data(176).logicalSrcIdx = 369;
                    section.data(176).dtTransOffset = 193;

                    ;% UAM_Flight_control_P.Gain3_Gain_i
                    section.data(177).logicalSrcIdx = 370;
                    section.data(177).dtTransOffset = 194;

                    ;% UAM_Flight_control_P.value_Value
                    section.data(178).logicalSrcIdx = 371;
                    section.data(178).dtTransOffset = 195;

                    ;% UAM_Flight_control_P.Saturation3_UpperSat_c
                    section.data(179).logicalSrcIdx = 372;
                    section.data(179).dtTransOffset = 196;

                    ;% UAM_Flight_control_P.Saturation3_LowerSat_k
                    section.data(180).logicalSrcIdx = 373;
                    section.data(180).dtTransOffset = 197;

                    ;% UAM_Flight_control_P.Integrator_gainval_nm
                    section.data(181).logicalSrcIdx = 374;
                    section.data(181).dtTransOffset = 198;

                    ;% UAM_Flight_control_P.Filter_gainval_er
                    section.data(182).logicalSrcIdx = 375;
                    section.data(182).dtTransOffset = 199;

                    ;% UAM_Flight_control_P.Gain_Gain_at
                    section.data(183).logicalSrcIdx = 376;
                    section.data(183).dtTransOffset = 200;

                    ;% UAM_Flight_control_P.Saturation_UpperSat_o
                    section.data(184).logicalSrcIdx = 377;
                    section.data(184).dtTransOffset = 201;

                    ;% UAM_Flight_control_P.Saturation_LowerSat_j
                    section.data(185).logicalSrcIdx = 378;
                    section.data(185).dtTransOffset = 202;

                    ;% UAM_Flight_control_P.Clamping_zero_Value_p2
                    section.data(186).logicalSrcIdx = 379;
                    section.data(186).dtTransOffset = 203;

                    ;% UAM_Flight_control_P.Saturation2_UpperSat_j
                    section.data(187).logicalSrcIdx = 380;
                    section.data(187).dtTransOffset = 204;

                    ;% UAM_Flight_control_P.Saturation2_LowerSat_e0
                    section.data(188).logicalSrcIdx = 381;
                    section.data(188).dtTransOffset = 205;

                    ;% UAM_Flight_control_P.Gain_Gain_cg
                    section.data(189).logicalSrcIdx = 382;
                    section.data(189).dtTransOffset = 206;

                    ;% UAM_Flight_control_P.Integrator_gainval_e
                    section.data(190).logicalSrcIdx = 383;
                    section.data(190).dtTransOffset = 207;

                    ;% UAM_Flight_control_P.Filter_gainval_gl
                    section.data(191).logicalSrcIdx = 384;
                    section.data(191).dtTransOffset = 208;

                    ;% UAM_Flight_control_P.rad_Gain_k
                    section.data(192).logicalSrcIdx = 385;
                    section.data(192).dtTransOffset = 209;

                    ;% UAM_Flight_control_P.Saturation1_UpperSat_n
                    section.data(193).logicalSrcIdx = 386;
                    section.data(193).dtTransOffset = 210;

                    ;% UAM_Flight_control_P.Saturation1_LowerSat_o
                    section.data(194).logicalSrcIdx = 387;
                    section.data(194).dtTransOffset = 211;

                    ;% UAM_Flight_control_P.Clamping_zero_Value_h
                    section.data(195).logicalSrcIdx = 388;
                    section.data(195).dtTransOffset = 212;

                    ;% UAM_Flight_control_P.Saturation_UpperSat_dd
                    section.data(196).logicalSrcIdx = 389;
                    section.data(196).dtTransOffset = 213;

                    ;% UAM_Flight_control_P.Saturation_LowerSat_j2
                    section.data(197).logicalSrcIdx = 390;
                    section.data(197).dtTransOffset = 214;

                    ;% UAM_Flight_control_P.Saturation1_UpperSat_c
                    section.data(198).logicalSrcIdx = 391;
                    section.data(198).dtTransOffset = 215;

                    ;% UAM_Flight_control_P.Saturation1_LowerSat_oz
                    section.data(199).logicalSrcIdx = 392;
                    section.data(199).dtTransOffset = 216;

                    ;% UAM_Flight_control_P.Constant_Value_b
                    section.data(200).logicalSrcIdx = 393;
                    section.data(200).dtTransOffset = 217;

                    ;% UAM_Flight_control_P.Constant1_Value_a
                    section.data(201).logicalSrcIdx = 394;
                    section.data(201).dtTransOffset = 218;

                    ;% UAM_Flight_control_P.Constant1_Value_af
                    section.data(202).logicalSrcIdx = 395;
                    section.data(202).dtTransOffset = 219;

                    ;% UAM_Flight_control_P.Constant1_Value_m
                    section.data(203).logicalSrcIdx = 396;
                    section.data(203).dtTransOffset = 220;

                    ;% UAM_Flight_control_P.Constant1_Value_d2
                    section.data(204).logicalSrcIdx = 397;
                    section.data(204).dtTransOffset = 221;

                    ;% UAM_Flight_control_P.Integrator_gainval_a
                    section.data(205).logicalSrcIdx = 398;
                    section.data(205).dtTransOffset = 222;

                    ;% UAM_Flight_control_P.Gain1_Gain_j
                    section.data(206).logicalSrcIdx = 399;
                    section.data(206).dtTransOffset = 223;

                    ;% UAM_Flight_control_P.Merge1_InitialOutput
                    section.data(207).logicalSrcIdx = 400;
                    section.data(207).dtTransOffset = 224;

                    ;% UAM_Flight_control_P.Pitch_MAX_angle1_Gain
                    section.data(208).logicalSrcIdx = 401;
                    section.data(208).dtTransOffset = 225;

                    ;% UAM_Flight_control_P.Saturation1_UpperSat_l
                    section.data(209).logicalSrcIdx = 402;
                    section.data(209).dtTransOffset = 226;

                    ;% UAM_Flight_control_P.Saturation1_LowerSat_n
                    section.data(210).logicalSrcIdx = 403;
                    section.data(210).dtTransOffset = 227;

                    ;% UAM_Flight_control_P.Clamping_zero_Value_pg
                    section.data(211).logicalSrcIdx = 404;
                    section.data(211).dtTransOffset = 228;

                    ;% UAM_Flight_control_P.Integrator_gainval_on
                    section.data(212).logicalSrcIdx = 405;
                    section.data(212).dtTransOffset = 229;

                    ;% UAM_Flight_control_P.Filter_gainval_jc
                    section.data(213).logicalSrcIdx = 406;
                    section.data(213).dtTransOffset = 230;

                    ;% UAM_Flight_control_P.Merge_InitialOutput_gy
                    section.data(214).logicalSrcIdx = 407;
                    section.data(214).dtTransOffset = 231;

                    ;% UAM_Flight_control_P.Roll_MAX_angle_Gain_n
                    section.data(215).logicalSrcIdx = 408;
                    section.data(215).dtTransOffset = 232;

                    ;% UAM_Flight_control_P.Saturation_UpperSat_e4
                    section.data(216).logicalSrcIdx = 409;
                    section.data(216).dtTransOffset = 233;

                    ;% UAM_Flight_control_P.Saturation_LowerSat_o
                    section.data(217).logicalSrcIdx = 410;
                    section.data(217).dtTransOffset = 234;

                    ;% UAM_Flight_control_P.Clamping_zero_Value_i
                    section.data(218).logicalSrcIdx = 411;
                    section.data(218).dtTransOffset = 235;

                    ;% UAM_Flight_control_P.Integrator_gainval_j5
                    section.data(219).logicalSrcIdx = 412;
                    section.data(219).dtTransOffset = 236;

                    ;% UAM_Flight_control_P.Filter_gainval_lj
                    section.data(220).logicalSrcIdx = 413;
                    section.data(220).dtTransOffset = 237;

                    ;% UAM_Flight_control_P.Saturation5_UpperSat_n
                    section.data(221).logicalSrcIdx = 414;
                    section.data(221).dtTransOffset = 238;

                    ;% UAM_Flight_control_P.Saturation5_LowerSat_o
                    section.data(222).logicalSrcIdx = 415;
                    section.data(222).dtTransOffset = 239;

                    ;% UAM_Flight_control_P.Clamping_zero_Value_d
                    section.data(223).logicalSrcIdx = 416;
                    section.data(223).dtTransOffset = 240;

                    ;% UAM_Flight_control_P.Constant6_Value_o
                    section.data(224).logicalSrcIdx = 417;
                    section.data(224).dtTransOffset = 241;

                    ;% UAM_Flight_control_P.Constant4_Value_e
                    section.data(225).logicalSrcIdx = 418;
                    section.data(225).dtTransOffset = 242;

                    ;% UAM_Flight_control_P.Constant5_Value_l
                    section.data(226).logicalSrcIdx = 419;
                    section.data(226).dtTransOffset = 243;

                    ;% UAM_Flight_control_P.Constant1_Value_da
                    section.data(227).logicalSrcIdx = 420;
                    section.data(227).dtTransOffset = 244;

                    ;% UAM_Flight_control_P.Gain_Gain_e
                    section.data(228).logicalSrcIdx = 421;
                    section.data(228).dtTransOffset = 250;

                    ;% UAM_Flight_control_P.Switch_Threshold_a
                    section.data(229).logicalSrcIdx = 422;
                    section.data(229).dtTransOffset = 251;

                    ;% UAM_Flight_control_P.Constant_Value_k5
                    section.data(230).logicalSrcIdx = 423;
                    section.data(230).dtTransOffset = 252;

                    ;% UAM_Flight_control_P.Constant4_Value_j
                    section.data(231).logicalSrcIdx = 424;
                    section.data(231).dtTransOffset = 268;

                    ;% UAM_Flight_control_P.Saturation2_UpperSat_a
                    section.data(232).logicalSrcIdx = 425;
                    section.data(232).dtTransOffset = 269;

                    ;% UAM_Flight_control_P.Saturation2_LowerSat_d
                    section.data(233).logicalSrcIdx = 426;
                    section.data(233).dtTransOffset = 270;

                    ;% UAM_Flight_control_P.Saturation1_UpperSat_nf
                    section.data(234).logicalSrcIdx = 427;
                    section.data(234).dtTransOffset = 271;

                    ;% UAM_Flight_control_P.Saturation1_LowerSat_h
                    section.data(235).logicalSrcIdx = 428;
                    section.data(235).dtTransOffset = 272;

                    ;% UAM_Flight_control_P.Saturation3_UpperSat_g
                    section.data(236).logicalSrcIdx = 429;
                    section.data(236).dtTransOffset = 273;

                    ;% UAM_Flight_control_P.Saturation3_LowerSat_p
                    section.data(237).logicalSrcIdx = 430;
                    section.data(237).dtTransOffset = 274;

                    ;% UAM_Flight_control_P.Saturation4_UpperSat_g
                    section.data(238).logicalSrcIdx = 431;
                    section.data(238).dtTransOffset = 275;

                    ;% UAM_Flight_control_P.Saturation4_LowerSat_m
                    section.data(239).logicalSrcIdx = 432;
                    section.data(239).dtTransOffset = 276;

                    ;% UAM_Flight_control_P.Saturation4_UpperSat_m
                    section.data(240).logicalSrcIdx = 433;
                    section.data(240).dtTransOffset = 277;

                    ;% UAM_Flight_control_P.Saturation4_LowerSat_a
                    section.data(241).logicalSrcIdx = 434;
                    section.data(241).dtTransOffset = 278;

                    ;% UAM_Flight_control_P.Saturation1_UpperSat_b
                    section.data(242).logicalSrcIdx = 435;
                    section.data(242).dtTransOffset = 279;

                    ;% UAM_Flight_control_P.Saturation1_LowerSat_ir
                    section.data(243).logicalSrcIdx = 436;
                    section.data(243).dtTransOffset = 280;

                    ;% UAM_Flight_control_P.Saturation2_UpperSat_n
                    section.data(244).logicalSrcIdx = 437;
                    section.data(244).dtTransOffset = 281;

                    ;% UAM_Flight_control_P.Saturation2_LowerSat_g
                    section.data(245).logicalSrcIdx = 438;
                    section.data(245).dtTransOffset = 282;

                    ;% UAM_Flight_control_P.Saturation3_UpperSat_k
                    section.data(246).logicalSrcIdx = 439;
                    section.data(246).dtTransOffset = 283;

                    ;% UAM_Flight_control_P.Saturation3_LowerSat_n
                    section.data(247).logicalSrcIdx = 440;
                    section.data(247).dtTransOffset = 284;

                    ;% UAM_Flight_control_P.MotorActuatorCommands_Y0_f
                    section.data(248).logicalSrcIdx = 441;
                    section.data(248).dtTransOffset = 285;

                    ;% UAM_Flight_control_P.Merge_1_InitialOutput
                    section.data(249).logicalSrcIdx = 442;
                    section.data(249).dtTransOffset = 286;

                    ;% UAM_Flight_control_P.Gain1_Gain_c
                    section.data(250).logicalSrcIdx = 443;
                    section.data(250).dtTransOffset = 287;

                    ;% UAM_Flight_control_P.Constant2_Value_h
                    section.data(251).logicalSrcIdx = 444;
                    section.data(251).dtTransOffset = 288;

                    ;% UAM_Flight_control_P.Merge_2_InitialOutput_i
                    section.data(252).logicalSrcIdx = 445;
                    section.data(252).dtTransOffset = 289;

                    ;% UAM_Flight_control_P.Gain3_Gain_a
                    section.data(253).logicalSrcIdx = 446;
                    section.data(253).dtTransOffset = 290;

                    ;% UAM_Flight_control_P.Constant4_Value_je
                    section.data(254).logicalSrcIdx = 447;
                    section.data(254).dtTransOffset = 291;

                    ;% UAM_Flight_control_P.Merge_4_InitialOutput
                    section.data(255).logicalSrcIdx = 448;
                    section.data(255).dtTransOffset = 292;

                    ;% UAM_Flight_control_P.Gain5_Gain_a
                    section.data(256).logicalSrcIdx = 449;
                    section.data(256).dtTransOffset = 293;

                    ;% UAM_Flight_control_P.Constant6_Value_b
                    section.data(257).logicalSrcIdx = 450;
                    section.data(257).dtTransOffset = 294;

                    ;% UAM_Flight_control_P.Merge_3_InitialOutput_i
                    section.data(258).logicalSrcIdx = 451;
                    section.data(258).dtTransOffset = 295;

                    ;% UAM_Flight_control_P.Gain7_Gain_j
                    section.data(259).logicalSrcIdx = 452;
                    section.data(259).dtTransOffset = 296;

                    ;% UAM_Flight_control_P.Constant8_Value_a
                    section.data(260).logicalSrcIdx = 453;
                    section.data(260).dtTransOffset = 297;

                    ;% UAM_Flight_control_P.Constant_Value_gi
                    section.data(261).logicalSrcIdx = 454;
                    section.data(261).dtTransOffset = 298;

                    ;% UAM_Flight_control_P.Saturation_UpperSat_h
                    section.data(262).logicalSrcIdx = 455;
                    section.data(262).dtTransOffset = 299;

                    ;% UAM_Flight_control_P.Saturation_LowerSat_ff
                    section.data(263).logicalSrcIdx = 456;
                    section.data(263).dtTransOffset = 300;

                    ;% UAM_Flight_control_P.Saturation1_UpperSat_d
                    section.data(264).logicalSrcIdx = 457;
                    section.data(264).dtTransOffset = 301;

                    ;% UAM_Flight_control_P.Saturation1_LowerSat_d
                    section.data(265).logicalSrcIdx = 458;
                    section.data(265).dtTransOffset = 302;

                    ;% UAM_Flight_control_P.Saturation2_UpperSat_pi
                    section.data(266).logicalSrcIdx = 459;
                    section.data(266).dtTransOffset = 303;

                    ;% UAM_Flight_control_P.Saturation2_LowerSat_l
                    section.data(267).logicalSrcIdx = 460;
                    section.data(267).dtTransOffset = 304;

                    ;% UAM_Flight_control_P.Saturation3_UpperSat_a
                    section.data(268).logicalSrcIdx = 461;
                    section.data(268).dtTransOffset = 305;

                    ;% UAM_Flight_control_P.Saturation3_LowerSat_l
                    section.data(269).logicalSrcIdx = 462;
                    section.data(269).dtTransOffset = 306;

                    ;% UAM_Flight_control_P.Merge_5_InitialOutput_i
                    section.data(270).logicalSrcIdx = 463;
                    section.data(270).dtTransOffset = 307;

                    ;% UAM_Flight_control_P.Saturation4_UpperSat_i
                    section.data(271).logicalSrcIdx = 464;
                    section.data(271).dtTransOffset = 308;

                    ;% UAM_Flight_control_P.Saturation4_LowerSat_g
                    section.data(272).logicalSrcIdx = 465;
                    section.data(272).dtTransOffset = 309;

                    ;% UAM_Flight_control_P.Switch1_Threshold
                    section.data(273).logicalSrcIdx = 466;
                    section.data(273).dtTransOffset = 310;

                    ;% UAM_Flight_control_P.Constant_Value_i
                    section.data(274).logicalSrcIdx = 467;
                    section.data(274).dtTransOffset = 311;

                    ;% UAM_Flight_control_P.Constant2_Value_f
                    section.data(275).logicalSrcIdx = 468;
                    section.data(275).dtTransOffset = 312;

                    ;% UAM_Flight_control_P.Constant3_Value_o
                    section.data(276).logicalSrcIdx = 469;
                    section.data(276).dtTransOffset = 313;

                    ;% UAM_Flight_control_P.Constant7_Value
                    section.data(277).logicalSrcIdx = 470;
                    section.data(277).dtTransOffset = 314;

                    ;% UAM_Flight_control_P.AER_Y0_e
                    section.data(278).logicalSrcIdx = 471;
                    section.data(278).dtTransOffset = 315;

                    ;% UAM_Flight_control_P.Constant1_Value_fa
                    section.data(279).logicalSrcIdx = 472;
                    section.data(279).dtTransOffset = 316;

                    ;% UAM_Flight_control_P.Clamping_zero_Value_bh
                    section.data(280).logicalSrcIdx = 473;
                    section.data(280).dtTransOffset = 317;

                    ;% UAM_Flight_control_P.Integrator_gainval_ap
                    section.data(281).logicalSrcIdx = 474;
                    section.data(281).dtTransOffset = 318;

                    ;% UAM_Flight_control_P.Filter_gainval_d
                    section.data(282).logicalSrcIdx = 475;
                    section.data(282).dtTransOffset = 319;

                    ;% UAM_Flight_control_P.Saturation2_UpperSat_ad
                    section.data(283).logicalSrcIdx = 476;
                    section.data(283).dtTransOffset = 320;

                    ;% UAM_Flight_control_P.Saturation2_LowerSat_i
                    section.data(284).logicalSrcIdx = 477;
                    section.data(284).dtTransOffset = 321;

                    ;% UAM_Flight_control_P.Bias_Bias_b
                    section.data(285).logicalSrcIdx = 478;
                    section.data(285).dtTransOffset = 322;

                    ;% UAM_Flight_control_P.Gain_Gain_ag
                    section.data(286).logicalSrcIdx = 479;
                    section.data(286).dtTransOffset = 323;

                    ;% UAM_Flight_control_P.Gain1_Gain_dd
                    section.data(287).logicalSrcIdx = 480;
                    section.data(287).dtTransOffset = 324;

                    ;% UAM_Flight_control_P.Bias_Bias_g
                    section.data(288).logicalSrcIdx = 481;
                    section.data(288).dtTransOffset = 325;

                    ;% UAM_Flight_control_P.Gain_Gain_m
                    section.data(289).logicalSrcIdx = 482;
                    section.data(289).dtTransOffset = 326;

                    ;% UAM_Flight_control_P.Gain1_Gain_hk
                    section.data(290).logicalSrcIdx = 483;
                    section.data(290).dtTransOffset = 327;

                    ;% UAM_Flight_control_P.Saturation1_UpperSat_i
                    section.data(291).logicalSrcIdx = 484;
                    section.data(291).dtTransOffset = 328;

                    ;% UAM_Flight_control_P.Saturation1_LowerSat_g
                    section.data(292).logicalSrcIdx = 485;
                    section.data(292).dtTransOffset = 329;

                    ;% UAM_Flight_control_P.Saturation5_UpperSat_c
                    section.data(293).logicalSrcIdx = 486;
                    section.data(293).dtTransOffset = 330;

                    ;% UAM_Flight_control_P.Saturation5_LowerSat_b
                    section.data(294).logicalSrcIdx = 487;
                    section.data(294).dtTransOffset = 331;

                    ;% UAM_Flight_control_P.Saturation2_UpperSat_f
                    section.data(295).logicalSrcIdx = 488;
                    section.data(295).dtTransOffset = 332;

                    ;% UAM_Flight_control_P.Saturation2_LowerSat_j
                    section.data(296).logicalSrcIdx = 489;
                    section.data(296).dtTransOffset = 333;

                    ;% UAM_Flight_control_P.Saturation6_UpperSat
                    section.data(297).logicalSrcIdx = 490;
                    section.data(297).dtTransOffset = 334;

                    ;% UAM_Flight_control_P.Saturation6_LowerSat
                    section.data(298).logicalSrcIdx = 491;
                    section.data(298).dtTransOffset = 335;

                    ;% UAM_Flight_control_P.Saturation3_UpperSat_i
                    section.data(299).logicalSrcIdx = 492;
                    section.data(299).dtTransOffset = 336;

                    ;% UAM_Flight_control_P.Saturation3_LowerSat_c
                    section.data(300).logicalSrcIdx = 493;
                    section.data(300).dtTransOffset = 337;

                    ;% UAM_Flight_control_P.Saturation7_UpperSat
                    section.data(301).logicalSrcIdx = 494;
                    section.data(301).dtTransOffset = 338;

                    ;% UAM_Flight_control_P.Saturation7_LowerSat
                    section.data(302).logicalSrcIdx = 495;
                    section.data(302).dtTransOffset = 339;

                    ;% UAM_Flight_control_P.Constant4_Value_il
                    section.data(303).logicalSrcIdx = 496;
                    section.data(303).dtTransOffset = 340;

                    ;% UAM_Flight_control_P.Saturation_UpperSat_hi
                    section.data(304).logicalSrcIdx = 497;
                    section.data(304).dtTransOffset = 341;

                    ;% UAM_Flight_control_P.Saturation_LowerSat_i
                    section.data(305).logicalSrcIdx = 498;
                    section.data(305).dtTransOffset = 342;

                    ;% UAM_Flight_control_P.Saturation4_UpperSat_d
                    section.data(306).logicalSrcIdx = 499;
                    section.data(306).dtTransOffset = 343;

                    ;% UAM_Flight_control_P.Saturation4_LowerSat_gy
                    section.data(307).logicalSrcIdx = 500;
                    section.data(307).dtTransOffset = 344;

                    ;% UAM_Flight_control_P.Constant9_Value
                    section.data(308).logicalSrcIdx = 501;
                    section.data(308).dtTransOffset = 345;

                    ;% UAM_Flight_control_P.Constant10_Value
                    section.data(309).logicalSrcIdx = 502;
                    section.data(309).dtTransOffset = 346;

                    ;% UAM_Flight_control_P.Constant11_Value
                    section.data(310).logicalSrcIdx = 503;
                    section.data(310).dtTransOffset = 347;

                    ;% UAM_Flight_control_P.Constant8_Value_i
                    section.data(311).logicalSrcIdx = 504;
                    section.data(311).dtTransOffset = 348;

                    ;% UAM_Flight_control_P.Constant6_Value_n
                    section.data(312).logicalSrcIdx = 505;
                    section.data(312).dtTransOffset = 349;

                    ;% UAM_Flight_control_P.MotorActuatorCommands_Y0_j
                    section.data(313).logicalSrcIdx = 506;
                    section.data(313).dtTransOffset = 350;

                    ;% UAM_Flight_control_P.Merge_1_InitialOutput_f
                    section.data(314).logicalSrcIdx = 507;
                    section.data(314).dtTransOffset = 351;

                    ;% UAM_Flight_control_P.Gain5_Gain_g
                    section.data(315).logicalSrcIdx = 508;
                    section.data(315).dtTransOffset = 352;

                    ;% UAM_Flight_control_P.Bias_Bias_be
                    section.data(316).logicalSrcIdx = 509;
                    section.data(316).dtTransOffset = 353;

                    ;% UAM_Flight_control_P.Merge_2_InitialOutput_f
                    section.data(317).logicalSrcIdx = 510;
                    section.data(317).dtTransOffset = 354;

                    ;% UAM_Flight_control_P.Gain6_Gain
                    section.data(318).logicalSrcIdx = 511;
                    section.data(318).dtTransOffset = 355;

                    ;% UAM_Flight_control_P.Bias1_Bias_p
                    section.data(319).logicalSrcIdx = 512;
                    section.data(319).dtTransOffset = 356;

                    ;% UAM_Flight_control_P.Merge_3_InitialOutput_f
                    section.data(320).logicalSrcIdx = 513;
                    section.data(320).dtTransOffset = 357;

                    ;% UAM_Flight_control_P.Gain7_Gain_c
                    section.data(321).logicalSrcIdx = 514;
                    section.data(321).dtTransOffset = 358;

                    ;% UAM_Flight_control_P.Bias2_Bias
                    section.data(322).logicalSrcIdx = 515;
                    section.data(322).dtTransOffset = 359;

                    ;% UAM_Flight_control_P.Merge_4_InitialOutput_f
                    section.data(323).logicalSrcIdx = 516;
                    section.data(323).dtTransOffset = 360;

                    ;% UAM_Flight_control_P.Gain8_Gain
                    section.data(324).logicalSrcIdx = 517;
                    section.data(324).dtTransOffset = 361;

                    ;% UAM_Flight_control_P.Bias3_Bias
                    section.data(325).logicalSrcIdx = 518;
                    section.data(325).dtTransOffset = 362;

                    ;% UAM_Flight_control_P.Merge_5_InitialOutput_f
                    section.data(326).logicalSrcIdx = 519;
                    section.data(326).dtTransOffset = 363;

                    ;% UAM_Flight_control_P.Gain9_Gain
                    section.data(327).logicalSrcIdx = 520;
                    section.data(327).dtTransOffset = 364;

                    ;% UAM_Flight_control_P.Bias4_Bias
                    section.data(328).logicalSrcIdx = 521;
                    section.data(328).dtTransOffset = 365;

                    ;% UAM_Flight_control_P.Constant_Value_ob
                    section.data(329).logicalSrcIdx = 522;
                    section.data(329).dtTransOffset = 366;

                    ;% UAM_Flight_control_P.Saturation_UpperSat_b
                    section.data(330).logicalSrcIdx = 523;
                    section.data(330).dtTransOffset = 367;

                    ;% UAM_Flight_control_P.Saturation_LowerSat_d
                    section.data(331).logicalSrcIdx = 524;
                    section.data(331).dtTransOffset = 368;

                    ;% UAM_Flight_control_P.Saturation1_UpperSat_cc
                    section.data(332).logicalSrcIdx = 525;
                    section.data(332).dtTransOffset = 369;

                    ;% UAM_Flight_control_P.Saturation1_LowerSat_bx
                    section.data(333).logicalSrcIdx = 526;
                    section.data(333).dtTransOffset = 370;

                    ;% UAM_Flight_control_P.Saturation2_UpperSat_bs
                    section.data(334).logicalSrcIdx = 527;
                    section.data(334).dtTransOffset = 371;

                    ;% UAM_Flight_control_P.Saturation2_LowerSat_h
                    section.data(335).logicalSrcIdx = 528;
                    section.data(335).dtTransOffset = 372;

                    ;% UAM_Flight_control_P.Saturation3_UpperSat_f
                    section.data(336).logicalSrcIdx = 529;
                    section.data(336).dtTransOffset = 373;

                    ;% UAM_Flight_control_P.Saturation3_LowerSat_j
                    section.data(337).logicalSrcIdx = 530;
                    section.data(337).dtTransOffset = 374;

                    ;% UAM_Flight_control_P.Saturation4_UpperSat_b
                    section.data(338).logicalSrcIdx = 531;
                    section.data(338).dtTransOffset = 375;

                    ;% UAM_Flight_control_P.Saturation4_LowerSat_c
                    section.data(339).logicalSrcIdx = 532;
                    section.data(339).dtTransOffset = 376;

                    ;% UAM_Flight_control_P.Bias_Bias_a
                    section.data(340).logicalSrcIdx = 533;
                    section.data(340).dtTransOffset = 377;

                    ;% UAM_Flight_control_P.Gain_Gain_b4
                    section.data(341).logicalSrcIdx = 534;
                    section.data(341).dtTransOffset = 378;

                    ;% UAM_Flight_control_P.Filter_gainval_h
                    section.data(342).logicalSrcIdx = 535;
                    section.data(342).dtTransOffset = 379;

                    ;% UAM_Flight_control_P.Bias_Bias_d
                    section.data(343).logicalSrcIdx = 536;
                    section.data(343).dtTransOffset = 380;

                    ;% UAM_Flight_control_P.Gain_Gain_d
                    section.data(344).logicalSrcIdx = 537;
                    section.data(344).dtTransOffset = 381;

                    ;% UAM_Flight_control_P.Saturation_UpperSat_j
                    section.data(345).logicalSrcIdx = 538;
                    section.data(345).dtTransOffset = 382;

                    ;% UAM_Flight_control_P.Saturation_LowerSat_bu
                    section.data(346).logicalSrcIdx = 539;
                    section.data(346).dtTransOffset = 383;

                    ;% UAM_Flight_control_P.UnitDelay_1_InitialCondition
                    section.data(347).logicalSrcIdx = 540;
                    section.data(347).dtTransOffset = 384;

                    ;% UAM_Flight_control_P.UnitDelay_2_InitialCondition_g
                    section.data(348).logicalSrcIdx = 541;
                    section.data(348).dtTransOffset = 385;

                    ;% UAM_Flight_control_P.UnitDelay_3_InitialCondition_g
                    section.data(349).logicalSrcIdx = 542;
                    section.data(349).dtTransOffset = 386;

                    ;% UAM_Flight_control_P.UnitDelay_4_InitialCondition
                    section.data(350).logicalSrcIdx = 543;
                    section.data(350).dtTransOffset = 387;

                    ;% UAM_Flight_control_P.Gain_Gain_cf
                    section.data(351).logicalSrcIdx = 544;
                    section.data(351).dtTransOffset = 388;

                    ;% UAM_Flight_control_P.Constant1_Value_hc
                    section.data(352).logicalSrcIdx = 545;
                    section.data(352).dtTransOffset = 389;

                    ;% UAM_Flight_control_P.Constant2_Value_a
                    section.data(353).logicalSrcIdx = 546;
                    section.data(353).dtTransOffset = 390;

                    ;% UAM_Flight_control_P.Constant_Value_l
                    section.data(354).logicalSrcIdx = 547;
                    section.data(354).dtTransOffset = 391;

                    ;% UAM_Flight_control_P.Constant1_Value_m4
                    section.data(355).logicalSrcIdx = 548;
                    section.data(355).dtTransOffset = 392;

                    ;% UAM_Flight_control_P.Constant1_Value_ha
                    section.data(356).logicalSrcIdx = 549;
                    section.data(356).dtTransOffset = 393;

                    ;% UAM_Flight_control_P.Constant3_Value_m
                    section.data(357).logicalSrcIdx = 550;
                    section.data(357).dtTransOffset = 394;

                    ;% UAM_Flight_control_P.Constant1_Value_ag
                    section.data(358).logicalSrcIdx = 551;
                    section.data(358).dtTransOffset = 397;

                    ;% UAM_Flight_control_P.Constant2_Value_e
                    section.data(359).logicalSrcIdx = 552;
                    section.data(359).dtTransOffset = 398;

                    ;% UAM_Flight_control_P.Constant_Value_j
                    section.data(360).logicalSrcIdx = 553;
                    section.data(360).dtTransOffset = 399;

                    ;% UAM_Flight_control_P.Constant_Value_p
                    section.data(361).logicalSrcIdx = 554;
                    section.data(361).dtTransOffset = 400;

                    ;% UAM_Flight_control_P.HdgCmdSat_UpperSat
                    section.data(362).logicalSrcIdx = 555;
                    section.data(362).dtTransOffset = 401;

                    ;% UAM_Flight_control_P.HdgCmdSat_LowerSat
                    section.data(363).logicalSrcIdx = 556;
                    section.data(363).dtTransOffset = 402;

                    ;% UAM_Flight_control_P.YawCmdSat_UpperSat
                    section.data(364).logicalSrcIdx = 557;
                    section.data(364).dtTransOffset = 403;

                    ;% UAM_Flight_control_P.YawCmdSat_LowerSat
                    section.data(365).logicalSrcIdx = 558;
                    section.data(365).dtTransOffset = 404;

                    ;% UAM_Flight_control_P.Constant1_Value_b
                    section.data(366).logicalSrcIdx = 559;
                    section.data(366).dtTransOffset = 405;

                    ;% UAM_Flight_control_P.HdgCmdSat_UpperSat_j
                    section.data(367).logicalSrcIdx = 560;
                    section.data(367).dtTransOffset = 406;

                    ;% UAM_Flight_control_P.HdgCmdSat_LowerSat_b
                    section.data(368).logicalSrcIdx = 561;
                    section.data(368).dtTransOffset = 407;

                    ;% UAM_Flight_control_P.YawCmdSat_UpperSat_m
                    section.data(369).logicalSrcIdx = 562;
                    section.data(369).dtTransOffset = 408;

                    ;% UAM_Flight_control_P.YawCmdSat_LowerSat_o
                    section.data(370).logicalSrcIdx = 563;
                    section.data(370).dtTransOffset = 409;

                    ;% UAM_Flight_control_P.LookaheadDistance_Value
                    section.data(371).logicalSrcIdx = 564;
                    section.data(371).dtTransOffset = 410;

                    ;% UAM_Flight_control_P.LookaheadDistance_Value_l
                    section.data(372).logicalSrcIdx = 565;
                    section.data(372).dtTransOffset = 411;

                    ;% UAM_Flight_control_P.HdgCmdSat_UpperSat_e
                    section.data(373).logicalSrcIdx = 566;
                    section.data(373).dtTransOffset = 412;

                    ;% UAM_Flight_control_P.HdgCmdSat_LowerSat_f
                    section.data(374).logicalSrcIdx = 567;
                    section.data(374).dtTransOffset = 413;

                    ;% UAM_Flight_control_P.UnitDelay1_InitialCondition_j
                    section.data(375).logicalSrcIdx = 568;
                    section.data(375).dtTransOffset = 414;

                    ;% UAM_Flight_control_P.UnitDelay_InitialCondition_m
                    section.data(376).logicalSrcIdx = 569;
                    section.data(376).dtTransOffset = 415;

                    ;% UAM_Flight_control_P.Switch_Threshold_n
                    section.data(377).logicalSrcIdx = 570;
                    section.data(377).dtTransOffset = 416;

                    ;% UAM_Flight_control_P.YawCmdSat_UpperSat_f
                    section.data(378).logicalSrcIdx = 571;
                    section.data(378).dtTransOffset = 417;

                    ;% UAM_Flight_control_P.YawCmdSat_LowerSat_p
                    section.data(379).logicalSrcIdx = 572;
                    section.data(379).dtTransOffset = 418;

                    ;% UAM_Flight_control_P.Constant2_Value_hp
                    section.data(380).logicalSrcIdx = 573;
                    section.data(380).dtTransOffset = 419;

                    ;% UAM_Flight_control_P.HoldPositionValue_Y0
                    section.data(381).logicalSrcIdx = 574;
                    section.data(381).dtTransOffset = 420;

                    ;% UAM_Flight_control_P.Constant_Value_p1
                    section.data(382).logicalSrcIdx = 575;
                    section.data(382).dtTransOffset = 421;

                    ;% UAM_Flight_control_P.LookaheadDistance_Value_p
                    section.data(383).logicalSrcIdx = 576;
                    section.data(383).dtTransOffset = 422;

                    ;% UAM_Flight_control_P.YawCmdSat_UpperSat_o
                    section.data(384).logicalSrcIdx = 577;
                    section.data(384).dtTransOffset = 423;

                    ;% UAM_Flight_control_P.YawCmdSat_LowerSat_f
                    section.data(385).logicalSrcIdx = 578;
                    section.data(385).dtTransOffset = 424;

                    ;% UAM_Flight_control_P.Saturation_UpperSat_hb
                    section.data(386).logicalSrcIdx = 579;
                    section.data(386).dtTransOffset = 425;

                    ;% UAM_Flight_control_P.Saturation_LowerSat_m
                    section.data(387).logicalSrcIdx = 580;
                    section.data(387).dtTransOffset = 426;

                    ;% UAM_Flight_control_P.Constant1_Value_n
                    section.data(388).logicalSrcIdx = 581;
                    section.data(388).dtTransOffset = 427;

                    ;% UAM_Flight_control_P.UnitDelay_1_InitialCondition_d
                    section.data(389).logicalSrcIdx = 582;
                    section.data(389).dtTransOffset = 428;

                    ;% UAM_Flight_control_P.UnitDelay_2_InitialCondition_d
                    section.data(390).logicalSrcIdx = 583;
                    section.data(390).dtTransOffset = 429;

                    ;% UAM_Flight_control_P.UnitDelay_3_InitialCondition_d
                    section.data(391).logicalSrcIdx = 584;
                    section.data(391).dtTransOffset = 430;

                    ;% UAM_Flight_control_P.UnitDelay_4_InitialCondition_d
                    section.data(392).logicalSrcIdx = 585;
                    section.data(392).dtTransOffset = 431;

                    ;% UAM_Flight_control_P.UnitDelay_1_InitialCondition_l
                    section.data(393).logicalSrcIdx = 586;
                    section.data(393).dtTransOffset = 432;

                    ;% UAM_Flight_control_P.Constant_Value_f
                    section.data(394).logicalSrcIdx = 587;
                    section.data(394).dtTransOffset = 433;

                    ;% UAM_Flight_control_P.UnitDelay_2_InitialCondition_l
                    section.data(395).logicalSrcIdx = 588;
                    section.data(395).dtTransOffset = 434;

                    ;% UAM_Flight_control_P.Constant4_Value_k
                    section.data(396).logicalSrcIdx = 589;
                    section.data(396).dtTransOffset = 435;

                    ;% UAM_Flight_control_P.UnitDelay_3_InitialCondition_l
                    section.data(397).logicalSrcIdx = 590;
                    section.data(397).dtTransOffset = 436;

                    ;% UAM_Flight_control_P.Constant5_Value_d
                    section.data(398).logicalSrcIdx = 591;
                    section.data(398).dtTransOffset = 437;

                    ;% UAM_Flight_control_P.UnitDelay_4_InitialCondition_l
                    section.data(399).logicalSrcIdx = 592;
                    section.data(399).dtTransOffset = 438;

                    ;% UAM_Flight_control_P.Constant6_Value_a
                    section.data(400).logicalSrcIdx = 593;
                    section.data(400).dtTransOffset = 439;

                    ;% UAM_Flight_control_P.Constant3_Value_ol
                    section.data(401).logicalSrcIdx = 594;
                    section.data(401).dtTransOffset = 440;

                    ;% UAM_Flight_control_P.Constant1_Value_kd
                    section.data(402).logicalSrcIdx = 595;
                    section.data(402).dtTransOffset = 444;

                    ;% UAM_Flight_control_P.AHRS_AccelerometerNoise
                    section.data(403).logicalSrcIdx = 596;
                    section.data(403).dtTransOffset = 447;

                    ;% UAM_Flight_control_P.AHRS_GyroscopeNoise
                    section.data(404).logicalSrcIdx = 597;
                    section.data(404).dtTransOffset = 448;

                    ;% UAM_Flight_control_P.AHRS_MagnetometerNoise
                    section.data(405).logicalSrcIdx = 598;
                    section.data(405).dtTransOffset = 449;

                    ;% UAM_Flight_control_P.AHRS_GyroscopeDriftNoise
                    section.data(406).logicalSrcIdx = 599;
                    section.data(406).dtTransOffset = 450;

                    ;% UAM_Flight_control_P.AHRS_LinearAccelerationNoise
                    section.data(407).logicalSrcIdx = 600;
                    section.data(407).dtTransOffset = 451;

                    ;% UAM_Flight_control_P.AHRS_MagneticDisturbanceNoise
                    section.data(408).logicalSrcIdx = 601;
                    section.data(408).dtTransOffset = 452;

                    ;% UAM_Flight_control_P.AHRS_LinearAccelerationDecayFac
                    section.data(409).logicalSrcIdx = 602;
                    section.data(409).dtTransOffset = 453;

                    ;% UAM_Flight_control_P.AHRS_MagneticDisturbanceDecayFa
                    section.data(410).logicalSrcIdx = 603;
                    section.data(410).dtTransOffset = 454;

                    ;% UAM_Flight_control_P.AHRS_ExpectedMagneticFieldStren
                    section.data(411).logicalSrcIdx = 604;
                    section.data(411).dtTransOffset = 455;

                    ;% UAM_Flight_control_P.Constant_Value_gj
                    section.data(412).logicalSrcIdx = 605;
                    section.data(412).dtTransOffset = 456;

                    ;% UAM_Flight_control_P.Constant_Value_h
                    section.data(413).logicalSrcIdx = 606;
                    section.data(413).dtTransOffset = 459;

                    ;% UAM_Flight_control_P.Gain1_Gain_db
                    section.data(414).logicalSrcIdx = 607;
                    section.data(414).dtTransOffset = 460;

                    ;% UAM_Flight_control_P.Constant_Value_jz
                    section.data(415).logicalSrcIdx = 608;
                    section.data(415).dtTransOffset = 461;

                    ;% UAM_Flight_control_P.Gain1_Gain_n
                    section.data(416).logicalSrcIdx = 609;
                    section.data(416).dtTransOffset = 462;

                    ;% UAM_Flight_control_P.UnitDelay6_InitialCondition
                    section.data(417).logicalSrcIdx = 610;
                    section.data(417).dtTransOffset = 463;

                    ;% UAM_Flight_control_P.UnitDelay7_InitialCondition
                    section.data(418).logicalSrcIdx = 611;
                    section.data(418).dtTransOffset = 464;

                    ;% UAM_Flight_control_P.UnitDelay8_InitialCondition
                    section.data(419).logicalSrcIdx = 612;
                    section.data(419).dtTransOffset = 465;

                    ;% UAM_Flight_control_P.UnitDelay9_InitialCondition
                    section.data(420).logicalSrcIdx = 613;
                    section.data(420).dtTransOffset = 466;

                    ;% UAM_Flight_control_P.UnitDelay10_InitialCondition
                    section.data(421).logicalSrcIdx = 614;
                    section.data(421).dtTransOffset = 467;

                    ;% UAM_Flight_control_P.UnitDelay11_InitialCondition
                    section.data(422).logicalSrcIdx = 615;
                    section.data(422).dtTransOffset = 468;

                    ;% UAM_Flight_control_P.UnitDelay12_InitialCondition
                    section.data(423).logicalSrcIdx = 616;
                    section.data(423).dtTransOffset = 469;

                    ;% UAM_Flight_control_P.Constant3_Value_k
                    section.data(424).logicalSrcIdx = 617;
                    section.data(424).dtTransOffset = 470;

                    ;% UAM_Flight_control_P.Gain_Gain_iq
                    section.data(425).logicalSrcIdx = 618;
                    section.data(425).dtTransOffset = 471;

                    ;% UAM_Flight_control_P.UnitDelay1_9_InitialCondition
                    section.data(426).logicalSrcIdx = 619;
                    section.data(426).dtTransOffset = 472;

                    ;% UAM_Flight_control_P.UnitDelay1_8_InitialCondition
                    section.data(427).logicalSrcIdx = 620;
                    section.data(427).dtTransOffset = 473;

                    ;% UAM_Flight_control_P.UnitDelay1_6_InitialCondition
                    section.data(428).logicalSrcIdx = 621;
                    section.data(428).dtTransOffset = 474;

                    ;% UAM_Flight_control_P.UnitDelay1_5_InitialCondition
                    section.data(429).logicalSrcIdx = 622;
                    section.data(429).dtTransOffset = 475;

                    ;% UAM_Flight_control_P.UnitDelay1_4_InitialCondition
                    section.data(430).logicalSrcIdx = 623;
                    section.data(430).dtTransOffset = 476;

                    ;% UAM_Flight_control_P.UnitDelay1_3_InitialCondition
                    section.data(431).logicalSrcIdx = 624;
                    section.data(431).dtTransOffset = 477;

                    ;% UAM_Flight_control_P.UnitDelay1_2_InitialCondition
                    section.data(432).logicalSrcIdx = 625;
                    section.data(432).dtTransOffset = 478;

                    ;% UAM_Flight_control_P.UnitDelay1_1_InitialCondition
                    section.data(433).logicalSrcIdx = 626;
                    section.data(433).dtTransOffset = 479;

                    ;% UAM_Flight_control_P.UnitDelay2_InitialCondition
                    section.data(434).logicalSrcIdx = 627;
                    section.data(434).dtTransOffset = 480;

                    ;% UAM_Flight_control_P.UnitDelay1_10_InitialCondition
                    section.data(435).logicalSrcIdx = 628;
                    section.data(435).dtTransOffset = 481;

                    ;% UAM_Flight_control_P.Merge_1_InitialOutput_g
                    section.data(436).logicalSrcIdx = 629;
                    section.data(436).dtTransOffset = 482;

                    ;% UAM_Flight_control_P.Merge_2_InitialOutput_g
                    section.data(437).logicalSrcIdx = 630;
                    section.data(437).dtTransOffset = 483;

                    ;% UAM_Flight_control_P.Merge_3_InitialOutput_g
                    section.data(438).logicalSrcIdx = 631;
                    section.data(438).dtTransOffset = 484;

                    ;% UAM_Flight_control_P.Merge_4_InitialOutput_g
                    section.data(439).logicalSrcIdx = 632;
                    section.data(439).dtTransOffset = 485;

                    ;% UAM_Flight_control_P.Merge_1_InitialOutput_e
                    section.data(440).logicalSrcIdx = 633;
                    section.data(440).dtTransOffset = 486;

                    ;% UAM_Flight_control_P.Merge_2_InitialOutput_e
                    section.data(441).logicalSrcIdx = 634;
                    section.data(441).dtTransOffset = 487;

                    ;% UAM_Flight_control_P.Merge_3_InitialOutput_e
                    section.data(442).logicalSrcIdx = 635;
                    section.data(442).dtTransOffset = 488;

                    ;% UAM_Flight_control_P.Merge_4_InitialOutput_e
                    section.data(443).logicalSrcIdx = 636;
                    section.data(443).dtTransOffset = 489;

                    ;% UAM_Flight_control_P.Merge_9_InitialOutput
                    section.data(444).logicalSrcIdx = 637;
                    section.data(444).dtTransOffset = 490;

                    ;% UAM_Flight_control_P.Merge_10_InitialOutput_e
                    section.data(445).logicalSrcIdx = 638;
                    section.data(445).dtTransOffset = 491;

                    ;% UAM_Flight_control_P.Merge_18_InitialOutput
                    section.data(446).logicalSrcIdx = 639;
                    section.data(446).dtTransOffset = 492;

                    ;% UAM_Flight_control_P.Merge_19_InitialOutput
                    section.data(447).logicalSrcIdx = 640;
                    section.data(447).dtTransOffset = 493;

                    ;% UAM_Flight_control_P.Merge_20_InitialOutput
                    section.data(448).logicalSrcIdx = 641;
                    section.data(448).dtTransOffset = 494;

                    ;% UAM_Flight_control_P.Merge_21_InitialOutput
                    section.data(449).logicalSrcIdx = 642;
                    section.data(449).dtTransOffset = 495;

                    ;% UAM_Flight_control_P.Merge_22_InitialOutput
                    section.data(450).logicalSrcIdx = 643;
                    section.data(450).dtTransOffset = 496;

                    ;% UAM_Flight_control_P.Merge_23_InitialOutput
                    section.data(451).logicalSrcIdx = 644;
                    section.data(451).dtTransOffset = 497;

                    ;% UAM_Flight_control_P.Merge_24_InitialOutput
                    section.data(452).logicalSrcIdx = 645;
                    section.data(452).dtTransOffset = 498;

                    ;% UAM_Flight_control_P.Merge_25_InitialOutput
                    section.data(453).logicalSrcIdx = 646;
                    section.data(453).dtTransOffset = 499;

                    ;% UAM_Flight_control_P.Merge_29_InitialOutput
                    section.data(454).logicalSrcIdx = 647;
                    section.data(454).dtTransOffset = 500;

                    ;% UAM_Flight_control_P.Merge_30_InitialOutput
                    section.data(455).logicalSrcIdx = 648;
                    section.data(455).dtTransOffset = 501;

                    ;% UAM_Flight_control_P.Merge_31_InitialOutput
                    section.data(456).logicalSrcIdx = 649;
                    section.data(456).dtTransOffset = 502;

                    ;% UAM_Flight_control_P.Merge_32_InitialOutput
                    section.data(457).logicalSrcIdx = 650;
                    section.data(457).dtTransOffset = 503;

                    ;% UAM_Flight_control_P.Merge_33_InitialOutput
                    section.data(458).logicalSrcIdx = 651;
                    section.data(458).dtTransOffset = 504;

                    ;% UAM_Flight_control_P.Merge_34_InitialOutput
                    section.data(459).logicalSrcIdx = 652;
                    section.data(459).dtTransOffset = 505;

                    ;% UAM_Flight_control_P.Merge_35_InitialOutput
                    section.data(460).logicalSrcIdx = 653;
                    section.data(460).dtTransOffset = 506;

                    ;% UAM_Flight_control_P.Merge_36_InitialOutput
                    section.data(461).logicalSrcIdx = 654;
                    section.data(461).dtTransOffset = 507;

                    ;% UAM_Flight_control_P.Merge_37_InitialOutput
                    section.data(462).logicalSrcIdx = 655;
                    section.data(462).dtTransOffset = 508;

                    ;% UAM_Flight_control_P.Merge_38_InitialOutput
                    section.data(463).logicalSrcIdx = 656;
                    section.data(463).dtTransOffset = 509;

                    ;% UAM_Flight_control_P.Merge_39_InitialOutput
                    section.data(464).logicalSrcIdx = 657;
                    section.data(464).dtTransOffset = 510;

                    ;% UAM_Flight_control_P.Merge_48_InitialOutput
                    section.data(465).logicalSrcIdx = 658;
                    section.data(465).dtTransOffset = 511;

                    ;% UAM_Flight_control_P.Merge_49_InitialOutput
                    section.data(466).logicalSrcIdx = 659;
                    section.data(466).dtTransOffset = 512;

                    ;% UAM_Flight_control_P.Merge_50_InitialOutput
                    section.data(467).logicalSrcIdx = 660;
                    section.data(467).dtTransOffset = 513;

                    ;% UAM_Flight_control_P.ground_Value
                    section.data(468).logicalSrcIdx = 661;
                    section.data(468).dtTransOffset = 514;

                    ;% UAM_Flight_control_P.Merge_52_InitialOutput
                    section.data(469).logicalSrcIdx = 662;
                    section.data(469).dtTransOffset = 515;

                    ;% UAM_Flight_control_P.Merge_53_InitialOutput
                    section.data(470).logicalSrcIdx = 663;
                    section.data(470).dtTransOffset = 516;

                    ;% UAM_Flight_control_P.Merge_54_InitialOutput
                    section.data(471).logicalSrcIdx = 664;
                    section.data(471).dtTransOffset = 517;

                    ;% UAM_Flight_control_P.Merge_55_InitialOutput
                    section.data(472).logicalSrcIdx = 665;
                    section.data(472).dtTransOffset = 518;

                    ;% UAM_Flight_control_P.Merge_56_InitialOutput
                    section.data(473).logicalSrcIdx = 666;
                    section.data(473).dtTransOffset = 519;

                    ;% UAM_Flight_control_P.Merge_57_InitialOutput
                    section.data(474).logicalSrcIdx = 667;
                    section.data(474).dtTransOffset = 520;

                    ;% UAM_Flight_control_P.Merge_58_InitialOutput
                    section.data(475).logicalSrcIdx = 668;
                    section.data(475).dtTransOffset = 521;

                    ;% UAM_Flight_control_P.Merge_59_InitialOutput
                    section.data(476).logicalSrcIdx = 669;
                    section.data(476).dtTransOffset = 522;

                    ;% UAM_Flight_control_P.Merge_60_InitialOutput
                    section.data(477).logicalSrcIdx = 670;
                    section.data(477).dtTransOffset = 523;

                    ;% UAM_Flight_control_P.Merge_61_InitialOutput
                    section.data(478).logicalSrcIdx = 671;
                    section.data(478).dtTransOffset = 524;

                    ;% UAM_Flight_control_P.Merge_62_InitialOutput
                    section.data(479).logicalSrcIdx = 672;
                    section.data(479).dtTransOffset = 525;

                    ;% UAM_Flight_control_P.Merge_63_InitialOutput
                    section.data(480).logicalSrcIdx = 673;
                    section.data(480).dtTransOffset = 526;

                    ;% UAM_Flight_control_P.Merge_64_InitialOutput
                    section.data(481).logicalSrcIdx = 674;
                    section.data(481).dtTransOffset = 527;

                    ;% UAM_Flight_control_P.Merge_51_InitialOutput
                    section.data(482).logicalSrcIdx = 675;
                    section.data(482).dtTransOffset = 528;

                    ;% UAM_Flight_control_P.Merge_69_InitialOutput
                    section.data(483).logicalSrcIdx = 676;
                    section.data(483).dtTransOffset = 529;

                    ;% UAM_Flight_control_P.Merge_11_InitialOutput
                    section.data(484).logicalSrcIdx = 677;
                    section.data(484).dtTransOffset = 530;

                    ;% UAM_Flight_control_P.Merge_12_InitialOutput
                    section.data(485).logicalSrcIdx = 678;
                    section.data(485).dtTransOffset = 531;

                    ;% UAM_Flight_control_P.Merge_13_InitialOutput
                    section.data(486).logicalSrcIdx = 679;
                    section.data(486).dtTransOffset = 532;

                    ;% UAM_Flight_control_P.Merge_4_InitialOutput_l
                    section.data(487).logicalSrcIdx = 680;
                    section.data(487).dtTransOffset = 533;

                    ;% UAM_Flight_control_P.Merge_5_InitialOutput_l
                    section.data(488).logicalSrcIdx = 681;
                    section.data(488).dtTransOffset = 534;

                    ;% UAM_Flight_control_P.Merge_6_InitialOutput_l
                    section.data(489).logicalSrcIdx = 682;
                    section.data(489).dtTransOffset = 535;

                    ;% UAM_Flight_control_P.Merge_7_InitialOutput_l
                    section.data(490).logicalSrcIdx = 683;
                    section.data(490).dtTransOffset = 536;

                    ;% UAM_Flight_control_P.Merge_8_InitialOutput
                    section.data(491).logicalSrcIdx = 684;
                    section.data(491).dtTransOffset = 537;

                    ;% UAM_Flight_control_P.Merge_9_InitialOutput_l
                    section.data(492).logicalSrcIdx = 685;
                    section.data(492).dtTransOffset = 538;

                    ;% UAM_Flight_control_P.Gain_Gain_n
                    section.data(493).logicalSrcIdx = 686;
                    section.data(493).dtTransOffset = 539;

                    ;% UAM_Flight_control_P.Gain1_Gain_l
                    section.data(494).logicalSrcIdx = 687;
                    section.data(494).dtTransOffset = 540;

                    ;% UAM_Flight_control_P.Constant1_Value_gm
                    section.data(495).logicalSrcIdx = 688;
                    section.data(495).dtTransOffset = 541;

            nTotData = nTotData + section.nData;
            paramMap.sections(49) = section;
            clear section

            section.nData     = 10;
            section.data(10)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Constant_Value_n
                    section.data(1).logicalSrcIdx = 689;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_P.Constant1_Value_k2
                    section.data(2).logicalSrcIdx = 690;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_P.Constant4_Value_ib
                    section.data(3).logicalSrcIdx = 691;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_P.Constant_Value_l5
                    section.data(4).logicalSrcIdx = 692;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_P.Constant_Value_ie
                    section.data(5).logicalSrcIdx = 693;
                    section.data(5).dtTransOffset = 4;

                    ;% UAM_Flight_control_P.Constant1_Value_gz
                    section.data(6).logicalSrcIdx = 694;
                    section.data(6).dtTransOffset = 5;

                    ;% UAM_Flight_control_P.UnitDelay_8_InitialCondition
                    section.data(7).logicalSrcIdx = 695;
                    section.data(7).dtTransOffset = 6;

                    ;% UAM_Flight_control_P.UnitDelay_8_InitialCondition_d
                    section.data(8).logicalSrcIdx = 696;
                    section.data(8).dtTransOffset = 7;

                    ;% UAM_Flight_control_P.UnitDelay_8_InitialCondition_l
                    section.data(9).logicalSrcIdx = 697;
                    section.data(9).dtTransOffset = 8;

                    ;% UAM_Flight_control_P.Merge_8_InitialOutput_g
                    section.data(10).logicalSrcIdx = 698;
                    section.data(10).dtTransOffset = 9;

            nTotData = nTotData + section.nData;
            paramMap.sections(50) = section;
            clear section

            section.nData     = 13;
            section.data(13)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Merge_5_InitialOutput_e
                    section.data(1).logicalSrcIdx = 699;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_P.Merge_6_InitialOutput_e
                    section.data(2).logicalSrcIdx = 700;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_P.Merge_7_InitialOutput_e
                    section.data(3).logicalSrcIdx = 701;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_P.Merge_8_InitialOutput_e
                    section.data(4).logicalSrcIdx = 702;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_P.Merge_11_InitialOutput_e
                    section.data(5).logicalSrcIdx = 703;
                    section.data(5).dtTransOffset = 4;

                    ;% UAM_Flight_control_P.Merge_12_InitialOutput_e
                    section.data(6).logicalSrcIdx = 704;
                    section.data(6).dtTransOffset = 5;

                    ;% UAM_Flight_control_P.Merge_13_InitialOutput_e
                    section.data(7).logicalSrcIdx = 705;
                    section.data(7).dtTransOffset = 6;

                    ;% UAM_Flight_control_P.Merge_15_InitialOutput
                    section.data(8).logicalSrcIdx = 706;
                    section.data(8).dtTransOffset = 7;

                    ;% UAM_Flight_control_P.Merge_16_InitialOutput
                    section.data(9).logicalSrcIdx = 707;
                    section.data(9).dtTransOffset = 8;

                    ;% UAM_Flight_control_P.Merge_17_InitialOutput
                    section.data(10).logicalSrcIdx = 708;
                    section.data(10).dtTransOffset = 9;

                    ;% UAM_Flight_control_P.Merge_26_InitialOutput
                    section.data(11).logicalSrcIdx = 709;
                    section.data(11).dtTransOffset = 10;

                    ;% UAM_Flight_control_P.Merge_27_InitialOutput
                    section.data(12).logicalSrcIdx = 710;
                    section.data(12).dtTransOffset = 11;

                    ;% UAM_Flight_control_P.Merge_28_InitialOutput
                    section.data(13).logicalSrcIdx = 711;
                    section.data(13).dtTransOffset = 12;

            nTotData = nTotData + section.nData;
            paramMap.sections(51) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Merge_40_InitialOutput
                    section.data(1).logicalSrcIdx = 712;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_P.Merge_41_InitialOutput
                    section.data(2).logicalSrcIdx = 713;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_P.Merge_42_InitialOutput
                    section.data(3).logicalSrcIdx = 714;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_P.Merge_43_InitialOutput
                    section.data(4).logicalSrcIdx = 715;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_P.Merge_44_InitialOutput
                    section.data(5).logicalSrcIdx = 716;
                    section.data(5).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            paramMap.sections(52) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Constant_Value_hf
                    section.data(1).logicalSrcIdx = 717;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_P.Constant_Value_a
                    section.data(2).logicalSrcIdx = 718;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_P.Constant_Value_ga
                    section.data(3).logicalSrcIdx = 719;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_P.Constant_Value_hg
                    section.data(4).logicalSrcIdx = 720;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_P.Constant_Value_dq
                    section.data(5).logicalSrcIdx = 721;
                    section.data(5).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            paramMap.sections(53) = section;
            clear section

            section.nData     = 52;
            section.data(52)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Constant_Value_jf
                    section.data(1).logicalSrcIdx = 722;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_P.Constant2_Value_h3
                    section.data(2).logicalSrcIdx = 723;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_P.Constant3_Value_c
                    section.data(3).logicalSrcIdx = 724;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_P.Constant4_Value_c
                    section.data(4).logicalSrcIdx = 725;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_P.Constant_Value_mm
                    section.data(5).logicalSrcIdx = 726;
                    section.data(5).dtTransOffset = 4;

                    ;% UAM_Flight_control_P.Constant2_Value_lk
                    section.data(6).logicalSrcIdx = 727;
                    section.data(6).dtTransOffset = 5;

                    ;% UAM_Flight_control_P.Constant3_Value_h
                    section.data(7).logicalSrcIdx = 728;
                    section.data(7).dtTransOffset = 6;

                    ;% UAM_Flight_control_P.Constant4_Value_in
                    section.data(8).logicalSrcIdx = 729;
                    section.data(8).dtTransOffset = 7;

                    ;% UAM_Flight_control_P.Constant_Value_pl
                    section.data(9).logicalSrcIdx = 730;
                    section.data(9).dtTransOffset = 8;

                    ;% UAM_Flight_control_P.Constant2_Value_ah
                    section.data(10).logicalSrcIdx = 731;
                    section.data(10).dtTransOffset = 9;

                    ;% UAM_Flight_control_P.Constant3_Value_p
                    section.data(11).logicalSrcIdx = 732;
                    section.data(11).dtTransOffset = 10;

                    ;% UAM_Flight_control_P.Constant4_Value_m
                    section.data(12).logicalSrcIdx = 733;
                    section.data(12).dtTransOffset = 11;

                    ;% UAM_Flight_control_P.Constant_Value_nq
                    section.data(13).logicalSrcIdx = 734;
                    section.data(13).dtTransOffset = 12;

                    ;% UAM_Flight_control_P.Constant2_Value_g
                    section.data(14).logicalSrcIdx = 735;
                    section.data(14).dtTransOffset = 13;

                    ;% UAM_Flight_control_P.Constant3_Value_od
                    section.data(15).logicalSrcIdx = 736;
                    section.data(15).dtTransOffset = 14;

                    ;% UAM_Flight_control_P.Constant4_Value_h
                    section.data(16).logicalSrcIdx = 737;
                    section.data(16).dtTransOffset = 15;

                    ;% UAM_Flight_control_P.Constant_Value_fs
                    section.data(17).logicalSrcIdx = 738;
                    section.data(17).dtTransOffset = 16;

                    ;% UAM_Flight_control_P.Constant2_Value_c
                    section.data(18).logicalSrcIdx = 739;
                    section.data(18).dtTransOffset = 17;

                    ;% UAM_Flight_control_P.Constant3_Value_a
                    section.data(19).logicalSrcIdx = 740;
                    section.data(19).dtTransOffset = 18;

                    ;% UAM_Flight_control_P.Constant4_Value_a
                    section.data(20).logicalSrcIdx = 741;
                    section.data(20).dtTransOffset = 19;

                    ;% UAM_Flight_control_P.Constant_Value_dr
                    section.data(21).logicalSrcIdx = 742;
                    section.data(21).dtTransOffset = 20;

                    ;% UAM_Flight_control_P.Constant2_Value_f2
                    section.data(22).logicalSrcIdx = 743;
                    section.data(22).dtTransOffset = 21;

                    ;% UAM_Flight_control_P.Constant3_Value_d
                    section.data(23).logicalSrcIdx = 744;
                    section.data(23).dtTransOffset = 22;

                    ;% UAM_Flight_control_P.Constant4_Value_he
                    section.data(24).logicalSrcIdx = 745;
                    section.data(24).dtTransOffset = 23;

                    ;% UAM_Flight_control_P.Constant_Value_m0
                    section.data(25).logicalSrcIdx = 746;
                    section.data(25).dtTransOffset = 24;

                    ;% UAM_Flight_control_P.Constant2_Value_c5
                    section.data(26).logicalSrcIdx = 747;
                    section.data(26).dtTransOffset = 25;

                    ;% UAM_Flight_control_P.Constant3_Value_du
                    section.data(27).logicalSrcIdx = 748;
                    section.data(27).dtTransOffset = 26;

                    ;% UAM_Flight_control_P.Constant4_Value_ce
                    section.data(28).logicalSrcIdx = 749;
                    section.data(28).dtTransOffset = 27;

                    ;% UAM_Flight_control_P.Constant_Value_lj
                    section.data(29).logicalSrcIdx = 750;
                    section.data(29).dtTransOffset = 28;

                    ;% UAM_Flight_control_P.Constant2_Value_b
                    section.data(30).logicalSrcIdx = 751;
                    section.data(30).dtTransOffset = 29;

                    ;% UAM_Flight_control_P.Constant3_Value_g
                    section.data(31).logicalSrcIdx = 752;
                    section.data(31).dtTransOffset = 30;

                    ;% UAM_Flight_control_P.Constant4_Value_hs
                    section.data(32).logicalSrcIdx = 753;
                    section.data(32).dtTransOffset = 31;

                    ;% UAM_Flight_control_P.Constant_Value_ae
                    section.data(33).logicalSrcIdx = 754;
                    section.data(33).dtTransOffset = 32;

                    ;% UAM_Flight_control_P.Constant2_Value_k
                    section.data(34).logicalSrcIdx = 755;
                    section.data(34).dtTransOffset = 33;

                    ;% UAM_Flight_control_P.Constant3_Value_cl
                    section.data(35).logicalSrcIdx = 756;
                    section.data(35).dtTransOffset = 34;

                    ;% UAM_Flight_control_P.Constant4_Value_d
                    section.data(36).logicalSrcIdx = 757;
                    section.data(36).dtTransOffset = 35;

                    ;% UAM_Flight_control_P.Constant_Value_ln
                    section.data(37).logicalSrcIdx = 758;
                    section.data(37).dtTransOffset = 36;

                    ;% UAM_Flight_control_P.Constant2_Value_d
                    section.data(38).logicalSrcIdx = 759;
                    section.data(38).dtTransOffset = 37;

                    ;% UAM_Flight_control_P.Constant3_Value_k5
                    section.data(39).logicalSrcIdx = 760;
                    section.data(39).dtTransOffset = 38;

                    ;% UAM_Flight_control_P.Constant4_Value_dz
                    section.data(40).logicalSrcIdx = 761;
                    section.data(40).dtTransOffset = 39;

                    ;% UAM_Flight_control_P.Constant_Value_al
                    section.data(41).logicalSrcIdx = 762;
                    section.data(41).dtTransOffset = 40;

                    ;% UAM_Flight_control_P.Constant2_Value_bh
                    section.data(42).logicalSrcIdx = 763;
                    section.data(42).dtTransOffset = 41;

                    ;% UAM_Flight_control_P.Constant3_Value_ae
                    section.data(43).logicalSrcIdx = 764;
                    section.data(43).dtTransOffset = 42;

                    ;% UAM_Flight_control_P.Constant4_Value_o
                    section.data(44).logicalSrcIdx = 765;
                    section.data(44).dtTransOffset = 43;

                    ;% UAM_Flight_control_P.Constant_Value_pe
                    section.data(45).logicalSrcIdx = 766;
                    section.data(45).dtTransOffset = 44;

                    ;% UAM_Flight_control_P.Constant2_Value_bo
                    section.data(46).logicalSrcIdx = 767;
                    section.data(46).dtTransOffset = 45;

                    ;% UAM_Flight_control_P.Constant3_Value_aq
                    section.data(47).logicalSrcIdx = 768;
                    section.data(47).dtTransOffset = 46;

                    ;% UAM_Flight_control_P.Constant4_Value_jz
                    section.data(48).logicalSrcIdx = 769;
                    section.data(48).dtTransOffset = 47;

                    ;% UAM_Flight_control_P.Gain1_Gain_ms
                    section.data(49).logicalSrcIdx = 770;
                    section.data(49).dtTransOffset = 48;

                    ;% UAM_Flight_control_P.Gain1_Gain_dg
                    section.data(50).logicalSrcIdx = 771;
                    section.data(50).dtTransOffset = 49;

                    ;% UAM_Flight_control_P.DiscreteTimeIntegrator_IC
                    section.data(51).logicalSrcIdx = 772;
                    section.data(51).dtTransOffset = 50;

                    ;% UAM_Flight_control_P.DiscreteTimeIntegrator_IC_l
                    section.data(52).logicalSrcIdx = 773;
                    section.data(52).dtTransOffset = 51;

            nTotData = nTotData + section.nData;
            paramMap.sections(54) = section;
            clear section

            section.nData     = 30;
            section.data(30)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Gain_Gain_ck
                    section.data(1).logicalSrcIdx = 774;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_P.Gain_Gain_o
                    section.data(2).logicalSrcIdx = 775;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_P.UnitDelay_InitialCondition_l
                    section.data(3).logicalSrcIdx = 776;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_P.Switch_Threshold_g
                    section.data(4).logicalSrcIdx = 777;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_P.Switch_Threshold_c
                    section.data(5).logicalSrcIdx = 778;
                    section.data(5).dtTransOffset = 4;

                    ;% UAM_Flight_control_P.Switch1_Threshold_a
                    section.data(6).logicalSrcIdx = 779;
                    section.data(6).dtTransOffset = 5;

                    ;% UAM_Flight_control_P.Switch2_Threshold
                    section.data(7).logicalSrcIdx = 780;
                    section.data(7).dtTransOffset = 6;

                    ;% UAM_Flight_control_P.Switch4_Threshold
                    section.data(8).logicalSrcIdx = 781;
                    section.data(8).dtTransOffset = 7;

                    ;% UAM_Flight_control_P.UnitDelay_9_InitialCondition
                    section.data(9).logicalSrcIdx = 782;
                    section.data(9).dtTransOffset = 8;

                    ;% UAM_Flight_control_P.Constant3_Value_f
                    section.data(10).logicalSrcIdx = 783;
                    section.data(10).dtTransOffset = 9;

                    ;% UAM_Flight_control_P.Constant3_Value_az
                    section.data(11).logicalSrcIdx = 784;
                    section.data(11).dtTransOffset = 10;

                    ;% UAM_Flight_control_P.Constant3_Value_ph
                    section.data(12).logicalSrcIdx = 785;
                    section.data(12).dtTransOffset = 11;

                    ;% UAM_Flight_control_P.Constant_Value_j5
                    section.data(13).logicalSrcIdx = 786;
                    section.data(13).dtTransOffset = 12;

                    ;% UAM_Flight_control_P.Constant_Value_gm
                    section.data(14).logicalSrcIdx = 787;
                    section.data(14).dtTransOffset = 13;

                    ;% UAM_Flight_control_P.UnitDelay_9_InitialCondition_d
                    section.data(15).logicalSrcIdx = 788;
                    section.data(15).dtTransOffset = 14;

                    ;% UAM_Flight_control_P.UnitDelay_9_InitialCondition_l
                    section.data(16).logicalSrcIdx = 789;
                    section.data(16).dtTransOffset = 15;

                    ;% UAM_Flight_control_P.Constant3_Value_pj
                    section.data(17).logicalSrcIdx = 790;
                    section.data(17).dtTransOffset = 16;

                    ;% UAM_Flight_control_P.Constant_Value_av
                    section.data(18).logicalSrcIdx = 791;
                    section.data(18).dtTransOffset = 17;

                    ;% UAM_Flight_control_P.IC_Value_h
                    section.data(19).logicalSrcIdx = 792;
                    section.data(19).dtTransOffset = 18;

                    ;% UAM_Flight_control_P.Constant2_Value_fj
                    section.data(20).logicalSrcIdx = 793;
                    section.data(20).dtTransOffset = 19;

                    ;% UAM_Flight_control_P.UnitDelay_1_InitialCondition_e
                    section.data(21).logicalSrcIdx = 794;
                    section.data(21).dtTransOffset = 20;

                    ;% UAM_Flight_control_P.Merge_14_InitialOutput
                    section.data(22).logicalSrcIdx = 795;
                    section.data(22).dtTransOffset = 21;

                    ;% UAM_Flight_control_P.Merge_45_InitialOutput
                    section.data(23).logicalSrcIdx = 796;
                    section.data(23).dtTransOffset = 22;

                    ;% UAM_Flight_control_P.Merge_46_InitialOutput
                    section.data(24).logicalSrcIdx = 797;
                    section.data(24).dtTransOffset = 23;

                    ;% UAM_Flight_control_P.Merge_47_InitialOutput
                    section.data(25).logicalSrcIdx = 798;
                    section.data(25).dtTransOffset = 24;

                    ;% UAM_Flight_control_P.Merge_9_InitialOutput_g
                    section.data(26).logicalSrcIdx = 799;
                    section.data(26).dtTransOffset = 25;

                    ;% UAM_Flight_control_P.Merge_1_InitialOutput_l
                    section.data(27).logicalSrcIdx = 800;
                    section.data(27).dtTransOffset = 26;

                    ;% UAM_Flight_control_P.Merge_65_InitialOutput
                    section.data(28).logicalSrcIdx = 801;
                    section.data(28).dtTransOffset = 27;

                    ;% UAM_Flight_control_P.Merge_66_InitialOutput
                    section.data(29).logicalSrcIdx = 802;
                    section.data(29).dtTransOffset = 28;

                    ;% UAM_Flight_control_P.Merge_67_InitialOutput
                    section.data(30).logicalSrcIdx = 803;
                    section.data(30).dtTransOffset = 29;

            nTotData = nTotData + section.nData;
            paramMap.sections(55) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Emergency_b.Constant1_Value
                    section.data(1).logicalSrcIdx = 804;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(56) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Emergency_b.Constant2_Value
                    section.data(1).logicalSrcIdx = 805;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(57) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Emergency_b.Constant3_Value
                    section.data(1).logicalSrcIdx = 806;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(58) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem.Constant1_Value
                    section.data(1).logicalSrcIdx = 807;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(59) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem.Constant2_Value
                    section.data(1).logicalSrcIdx = 808;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(60) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem.Constant3_Value
                    section.data(1).logicalSrcIdx = 809;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(61) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem2_n.Saturation2_UpperSat
                    section.data(1).logicalSrcIdx = 810;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem2_n.Saturation2_LowerSat
                    section.data(2).logicalSrcIdx = 811;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem2_n.Constant_Value
                    section.data(3).logicalSrcIdx = 812;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem2_n.Constant2_Value
                    section.data(4).logicalSrcIdx = 813;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem2_n.Constant3_Value
                    section.data(5).logicalSrcIdx = 814;
                    section.data(5).dtTransOffset = 4;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem2_n.Constant4_Value
                    section.data(6).logicalSrcIdx = 815;
                    section.data(6).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            paramMap.sections(62) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem3_g.Constant_Value
                    section.data(1).logicalSrcIdx = 816;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem3_g.Constant1_Value
                    section.data(2).logicalSrcIdx = 817;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem3_g.Constant2_Value
                    section.data(3).logicalSrcIdx = 818;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem3_g.Constant3_Value
                    section.data(4).logicalSrcIdx = 819;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            paramMap.sections(63) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem1_m.Constant_Value
                    section.data(1).logicalSrcIdx = 820;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem1_m.Constant1_Value
                    section.data(2).logicalSrcIdx = 821;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem1_m.Constant2_Value
                    section.data(3).logicalSrcIdx = 822;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem1_m.Constant3_Value
                    section.data(4).logicalSrcIdx = 823;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            paramMap.sections(64) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem1_m.Switch_Threshold
                    section.data(1).logicalSrcIdx = 824;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(65) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem_e.Constant_Value
                    section.data(1).logicalSrcIdx = 825;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem_e.Constant1_Value
                    section.data(2).logicalSrcIdx = 826;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem_e.Constant2_Value
                    section.data(3).logicalSrcIdx = 827;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem_e.Constant3_Value
                    section.data(4).logicalSrcIdx = 828;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            paramMap.sections(66) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem2_m.Saturation2_UpperSat
                    section.data(1).logicalSrcIdx = 829;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem2_m.Saturation2_LowerSat
                    section.data(2).logicalSrcIdx = 830;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem2_m.Constant_Value
                    section.data(3).logicalSrcIdx = 831;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem2_m.Constant2_Value
                    section.data(4).logicalSrcIdx = 832;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem2_m.Constant3_Value
                    section.data(5).logicalSrcIdx = 833;
                    section.data(5).dtTransOffset = 4;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem2_m.Constant4_Value
                    section.data(6).logicalSrcIdx = 834;
                    section.data(6).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            paramMap.sections(67) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem3_e.Constant_Value
                    section.data(1).logicalSrcIdx = 835;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem3_e.Constant1_Value
                    section.data(2).logicalSrcIdx = 836;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem3_e.Constant2_Value
                    section.data(3).logicalSrcIdx = 837;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem3_e.Constant3_Value
                    section.data(4).logicalSrcIdx = 838;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            paramMap.sections(68) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem_g.Constant_Value
                    section.data(1).logicalSrcIdx = 839;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem_g.Constant1_Value
                    section.data(2).logicalSrcIdx = 840;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem_g.Constant2_Value
                    section.data(3).logicalSrcIdx = 841;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem_g.Constant3_Value
                    section.data(4).logicalSrcIdx = 842;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            paramMap.sections(69) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem3.Constant_Value
                    section.data(1).logicalSrcIdx = 843;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem3.Constant1_Value
                    section.data(2).logicalSrcIdx = 844;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem3.Constant2_Value
                    section.data(3).logicalSrcIdx = 845;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem3.Constant3_Value
                    section.data(4).logicalSrcIdx = 846;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            paramMap.sections(70) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem1_e.Constant_Value
                    section.data(1).logicalSrcIdx = 847;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem1_e.Constant1_Value
                    section.data(2).logicalSrcIdx = 848;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem1_e.Constant2_Value
                    section.data(3).logicalSrcIdx = 849;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem1_e.Constant3_Value
                    section.data(4).logicalSrcIdx = 850;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            paramMap.sections(71) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem1_e.Switch_Threshold
                    section.data(1).logicalSrcIdx = 851;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(72) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem_kk.Constant_Value
                    section.data(1).logicalSrcIdx = 852;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem_kk.Constant1_Value
                    section.data(2).logicalSrcIdx = 853;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem_kk.Constant2_Value
                    section.data(3).logicalSrcIdx = 854;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem_kk.Constant3_Value
                    section.data(4).logicalSrcIdx = 855;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            paramMap.sections(73) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 17;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (UAM_Flight_control_B)
        ;%
            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% UAM_Flight_control_B.BusConversion_InsertedFor_Basic
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_B.BusConversion_InsertedFor_Guida
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_B.BusConversion_InsertedFor_Bas_n
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% UAM_Flight_control_B.FromWP
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_B.ToWP
                    section.data(2).logicalSrcIdx = 4;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_B.ToWP_b
                    section.data(3).logicalSrcIdx = 5;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_B.FromWP_k
                    section.data(4).logicalSrcIdx = 6;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_B.InnerLoopCmds
                    section.data(1).logicalSrcIdx = 7;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(3) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% UAM_Flight_control_B.controlMode_h
                    section.data(1).logicalSrcIdx = 8;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_B.controlMode_o
                    section.data(2).logicalSrcIdx = 9;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_B.controlMode_n
                    section.data(3).logicalSrcIdx = 10;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_B.controlMode_l
                    section.data(4).logicalSrcIdx = 11;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            sigMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_B.RotorParameters_g
                    section.data(1).logicalSrcIdx = 12;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(5) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% UAM_Flight_control_B.AACSP
                    section.data(1).logicalSrcIdx = 13;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_B.aacSP
                    section.data(2).logicalSrcIdx = 14;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            sigMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_B.HoverSPBUS
                    section.data(1).logicalSrcIdx = 15;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(7) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% UAM_Flight_control_B.CtrlSurfaceCommands
                    section.data(1).logicalSrcIdx = 16;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_B.Merge
                    section.data(2).logicalSrcIdx = 17;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_B.OutportBufferForCtrlSurfaceComm
                    section.data(3).logicalSrcIdx = 18;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_B.Merge_b
                    section.data(4).logicalSrcIdx = 19;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_B.OutportBufferForCtrlSurfaceCo_i
                    section.data(5).logicalSrcIdx = 20;
                    section.data(5).dtTransOffset = 4;

                    ;% UAM_Flight_control_B.Merge_d
                    section.data(6).logicalSrcIdx = 21;
                    section.data(6).dtTransOffset = 5;

                    ;% UAM_Flight_control_B.OutportBufferForCtrlSurfaceC_i5
                    section.data(7).logicalSrcIdx = 22;
                    section.data(7).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            sigMap.sections(8) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% UAM_Flight_control_B.FixedWingSP
                    section.data(1).logicalSrcIdx = 23;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_B.FixedWingSP_l
                    section.data(2).logicalSrcIdx = 24;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            sigMap.sections(9) = section;
            clear section

            section.nData     = 348;
            section.data(348)  = dumData; %prealloc

                    ;% UAM_Flight_control_B.GPSCourse
                    section.data(1).logicalSrcIdx = 25;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_B.rc
                    section.data(2).logicalSrcIdx = 26;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_B.Gain1
                    section.data(3).logicalSrcIdx = 27;
                    section.data(3).dtTransOffset = 17;

                    ;% UAM_Flight_control_B.YPR
                    section.data(4).logicalSrcIdx = 28;
                    section.data(4).dtTransOffset = 20;

                    ;% UAM_Flight_control_B.acc_x
                    section.data(5).logicalSrcIdx = 29;
                    section.data(5).dtTransOffset = 23;

                    ;% UAM_Flight_control_B.acc_y
                    section.data(6).logicalSrcIdx = 30;
                    section.data(6).dtTransOffset = 24;

                    ;% UAM_Flight_control_B.acc_z
                    section.data(7).logicalSrcIdx = 31;
                    section.data(7).dtTransOffset = 25;

                    ;% UAM_Flight_control_B.Abb
                    section.data(8).logicalSrcIdx = 32;
                    section.data(8).dtTransOffset = 26;

                    ;% UAM_Flight_control_B.gyro_x
                    section.data(9).logicalSrcIdx = 33;
                    section.data(9).dtTransOffset = 29;

                    ;% UAM_Flight_control_B.gyro_y
                    section.data(10).logicalSrcIdx = 34;
                    section.data(10).dtTransOffset = 30;

                    ;% UAM_Flight_control_B.gyro_z
                    section.data(11).logicalSrcIdx = 35;
                    section.data(11).dtTransOffset = 31;

                    ;% UAM_Flight_control_B.Gyro
                    section.data(12).logicalSrcIdx = 36;
                    section.data(12).dtTransOffset = 32;

                    ;% UAM_Flight_control_B.pqr
                    section.data(13).logicalSrcIdx = 37;
                    section.data(13).dtTransOffset = 35;

                    ;% UAM_Flight_control_B.vel_n
                    section.data(14).logicalSrcIdx = 38;
                    section.data(14).dtTransOffset = 38;

                    ;% UAM_Flight_control_B.vel_e
                    section.data(15).logicalSrcIdx = 39;
                    section.data(15).dtTransOffset = 39;

                    ;% UAM_Flight_control_B.mag_x
                    section.data(16).logicalSrcIdx = 40;
                    section.data(16).dtTransOffset = 40;

                    ;% UAM_Flight_control_B.mag_y
                    section.data(17).logicalSrcIdx = 41;
                    section.data(17).dtTransOffset = 41;

                    ;% UAM_Flight_control_B.mag_z
                    section.data(18).logicalSrcIdx = 42;
                    section.data(18).dtTransOffset = 42;

                    ;% UAM_Flight_control_B.GPSVelocity
                    section.data(19).logicalSrcIdx = 43;
                    section.data(19).dtTransOffset = 43;

                    ;% UAM_Flight_control_B.Ve
                    section.data(20).logicalSrcIdx = 44;
                    section.data(20).dtTransOffset = 46;

                    ;% UAM_Flight_control_B.latitude
                    section.data(21).logicalSrcIdx = 45;
                    section.data(21).dtTransOffset = 49;

                    ;% UAM_Flight_control_B.longitude
                    section.data(22).logicalSrcIdx = 46;
                    section.data(22).dtTransOffset = 50;

                    ;% UAM_Flight_control_B.arm
                    section.data(23).logicalSrcIdx = 47;
                    section.data(23).dtTransOffset = 51;

                    ;% UAM_Flight_control_B.Xe
                    section.data(24).logicalSrcIdx = 48;
                    section.data(24).dtTransOffset = 52;

                    ;% UAM_Flight_control_B.airspeed
                    section.data(25).logicalSrcIdx = 49;
                    section.data(25).dtTransOffset = 55;

                    ;% UAM_Flight_control_B.gndspeed
                    section.data(26).logicalSrcIdx = 50;
                    section.data(26).dtTransOffset = 56;

                    ;% UAM_Flight_control_B.gndspeed_g
                    section.data(27).logicalSrcIdx = 51;
                    section.data(27).dtTransOffset = 57;

                    ;% UAM_Flight_control_B.course
                    section.data(28).logicalSrcIdx = 52;
                    section.data(28).dtTransOffset = 58;

                    ;% UAM_Flight_control_B.RC
                    section.data(29).logicalSrcIdx = 53;
                    section.data(29).dtTransOffset = 59;

                    ;% UAM_Flight_control_B.pose
                    section.data(30).logicalSrcIdx = 54;
                    section.data(30).dtTransOffset = 69;

                    ;% UAM_Flight_control_B.UnitDelay2
                    section.data(31).logicalSrcIdx = 55;
                    section.data(31).dtTransOffset = 73;

                    ;% UAM_Flight_control_B.ground
                    section.data(32).logicalSrcIdx = 56;
                    section.data(32).dtTransOffset = 74;

                    ;% UAM_Flight_control_B.pose_b
                    section.data(33).logicalSrcIdx = 57;
                    section.data(33).dtTransOffset = 75;

                    ;% UAM_Flight_control_B.RateTransition5
                    section.data(34).logicalSrcIdx = 58;
                    section.data(34).dtTransOffset = 79;

                    ;% UAM_Flight_control_B.X
                    section.data(35).logicalSrcIdx = 59;
                    section.data(35).dtTransOffset = 80;

                    ;% UAM_Flight_control_B.Y
                    section.data(36).logicalSrcIdx = 60;
                    section.data(36).dtTransOffset = 81;

                    ;% UAM_Flight_control_B.Z
                    section.data(37).logicalSrcIdx = 61;
                    section.data(37).dtTransOffset = 82;

                    ;% UAM_Flight_control_B.Yaw
                    section.data(38).logicalSrcIdx = 62;
                    section.data(38).dtTransOffset = 83;

                    ;% UAM_Flight_control_B.roll
                    section.data(39).logicalSrcIdx = 63;
                    section.data(39).dtTransOffset = 84;

                    ;% UAM_Flight_control_B.pitch
                    section.data(40).logicalSrcIdx = 64;
                    section.data(40).dtTransOffset = 85;

                    ;% UAM_Flight_control_B.yaw
                    section.data(41).logicalSrcIdx = 65;
                    section.data(41).dtTransOffset = 86;

                    ;% UAM_Flight_control_B.altitude
                    section.data(42).logicalSrcIdx = 66;
                    section.data(42).dtTransOffset = 87;

                    ;% UAM_Flight_control_B.latitude_m
                    section.data(43).logicalSrcIdx = 67;
                    section.data(43).dtTransOffset = 88;

                    ;% UAM_Flight_control_B.longitude_f
                    section.data(44).logicalSrcIdx = 68;
                    section.data(44).dtTransOffset = 89;

                    ;% UAM_Flight_control_B.acc_x_f
                    section.data(45).logicalSrcIdx = 69;
                    section.data(45).dtTransOffset = 90;

                    ;% UAM_Flight_control_B.acc_y_j
                    section.data(46).logicalSrcIdx = 70;
                    section.data(46).dtTransOffset = 91;

                    ;% UAM_Flight_control_B.acc_z_l
                    section.data(47).logicalSrcIdx = 71;
                    section.data(47).dtTransOffset = 92;

                    ;% UAM_Flight_control_B.pressure
                    section.data(48).logicalSrcIdx = 72;
                    section.data(48).dtTransOffset = 93;

                    ;% UAM_Flight_control_B.vel_n_j
                    section.data(49).logicalSrcIdx = 73;
                    section.data(49).dtTransOffset = 94;

                    ;% UAM_Flight_control_B.vel_e_b
                    section.data(50).logicalSrcIdx = 74;
                    section.data(50).dtTransOffset = 95;

                    ;% UAM_Flight_control_B.vel_d
                    section.data(51).logicalSrcIdx = 75;
                    section.data(51).dtTransOffset = 96;

                    ;% UAM_Flight_control_B.gndspeed_f
                    section.data(52).logicalSrcIdx = 76;
                    section.data(52).dtTransOffset = 97;

                    ;% UAM_Flight_control_B.gyro_x_j
                    section.data(53).logicalSrcIdx = 77;
                    section.data(53).dtTransOffset = 98;

                    ;% UAM_Flight_control_B.gyro_y_j
                    section.data(54).logicalSrcIdx = 78;
                    section.data(54).dtTransOffset = 99;

                    ;% UAM_Flight_control_B.gyro_z_d
                    section.data(55).logicalSrcIdx = 79;
                    section.data(55).dtTransOffset = 100;

                    ;% UAM_Flight_control_B.mag_x_g
                    section.data(56).logicalSrcIdx = 80;
                    section.data(56).dtTransOffset = 101;

                    ;% UAM_Flight_control_B.mag_y_o
                    section.data(57).logicalSrcIdx = 81;
                    section.data(57).dtTransOffset = 102;

                    ;% UAM_Flight_control_B.mag_z_a
                    section.data(58).logicalSrcIdx = 82;
                    section.data(58).dtTransOffset = 103;

                    ;% UAM_Flight_control_B.lin_acc_ecef_x
                    section.data(59).logicalSrcIdx = 83;
                    section.data(59).dtTransOffset = 104;

                    ;% UAM_Flight_control_B.lin_acc_ecef_y
                    section.data(60).logicalSrcIdx = 84;
                    section.data(60).dtTransOffset = 105;

                    ;% UAM_Flight_control_B.lin_acc_ecef_z
                    section.data(61).logicalSrcIdx = 85;
                    section.data(61).dtTransOffset = 106;

                    ;% UAM_Flight_control_B.q
                    section.data(62).logicalSrcIdx = 86;
                    section.data(62).dtTransOffset = 107;

                    ;% UAM_Flight_control_B.airspeed_c
                    section.data(63).logicalSrcIdx = 87;
                    section.data(63).dtTransOffset = 111;

                    ;% UAM_Flight_control_B.m
                    section.data(64).logicalSrcIdx = 88;
                    section.data(64).dtTransOffset = 112;

                    ;% UAM_Flight_control_B.rc_j
                    section.data(65).logicalSrcIdx = 89;
                    section.data(65).dtTransOffset = 118;

                    ;% UAM_Flight_control_B.rpy_sp
                    section.data(66).logicalSrcIdx = 90;
                    section.data(66).dtTransOffset = 134;

                    ;% UAM_Flight_control_B.raw_acc_x
                    section.data(67).logicalSrcIdx = 91;
                    section.data(67).dtTransOffset = 137;

                    ;% UAM_Flight_control_B.raw_acc_y
                    section.data(68).logicalSrcIdx = 92;
                    section.data(68).dtTransOffset = 138;

                    ;% UAM_Flight_control_B.raw_acc_z
                    section.data(69).logicalSrcIdx = 93;
                    section.data(69).dtTransOffset = 139;

                    ;% UAM_Flight_control_B.raw_gyro_x
                    section.data(70).logicalSrcIdx = 94;
                    section.data(70).dtTransOffset = 140;

                    ;% UAM_Flight_control_B.raw_gyro_y
                    section.data(71).logicalSrcIdx = 95;
                    section.data(71).dtTransOffset = 141;

                    ;% UAM_Flight_control_B.raw_gyro_z
                    section.data(72).logicalSrcIdx = 96;
                    section.data(72).dtTransOffset = 142;

                    ;% UAM_Flight_control_B.raw_gps_lat
                    section.data(73).logicalSrcIdx = 97;
                    section.data(73).dtTransOffset = 143;

                    ;% UAM_Flight_control_B.raw_gps_lon
                    section.data(74).logicalSrcIdx = 98;
                    section.data(74).dtTransOffset = 144;

                    ;% UAM_Flight_control_B.raw_gps_alt
                    section.data(75).logicalSrcIdx = 99;
                    section.data(75).dtTransOffset = 145;

                    ;% UAM_Flight_control_B.raw_vel_n
                    section.data(76).logicalSrcIdx = 100;
                    section.data(76).dtTransOffset = 146;

                    ;% UAM_Flight_control_B.raw_vel_e
                    section.data(77).logicalSrcIdx = 101;
                    section.data(77).dtTransOffset = 147;

                    ;% UAM_Flight_control_B.raw_vel_d
                    section.data(78).logicalSrcIdx = 102;
                    section.data(78).dtTransOffset = 148;

                    ;% UAM_Flight_control_B.baro_alt
                    section.data(79).logicalSrcIdx = 103;
                    section.data(79).dtTransOffset = 149;

                    ;% UAM_Flight_control_B.q_d
                    section.data(80).logicalSrcIdx = 104;
                    section.data(80).dtTransOffset = 150;

                    ;% UAM_Flight_control_B.a
                    section.data(81).logicalSrcIdx = 106;
                    section.data(81).dtTransOffset = 154;

                    ;% UAM_Flight_control_B.RC_a
                    section.data(82).logicalSrcIdx = 107;
                    section.data(82).dtTransOffset = 155;

                    ;% UAM_Flight_control_B.target
                    section.data(83).logicalSrcIdx = 108;
                    section.data(83).dtTransOffset = 165;

                    ;% UAM_Flight_control_B.ground_o
                    section.data(84).logicalSrcIdx = 109;
                    section.data(84).dtTransOffset = 168;

                    ;% UAM_Flight_control_B.pose_h
                    section.data(85).logicalSrcIdx = 110;
                    section.data(85).dtTransOffset = 169;

                    ;% UAM_Flight_control_B.Euler
                    section.data(86).logicalSrcIdx = 111;
                    section.data(86).dtTransOffset = 173;

                    ;% UAM_Flight_control_B.pqr_n
                    section.data(87).logicalSrcIdx = 112;
                    section.data(87).dtTransOffset = 176;

                    ;% UAM_Flight_control_B.Ve_o
                    section.data(88).logicalSrcIdx = 113;
                    section.data(88).dtTransOffset = 179;

                    ;% UAM_Flight_control_B.Xe_i
                    section.data(89).logicalSrcIdx = 114;
                    section.data(89).dtTransOffset = 182;

                    ;% UAM_Flight_control_B.course_k
                    section.data(90).logicalSrcIdx = 115;
                    section.data(90).dtTransOffset = 185;

                    ;% UAM_Flight_control_B.Mag
                    section.data(91).logicalSrcIdx = 116;
                    section.data(91).dtTransOffset = 186;

                    ;% UAM_Flight_control_B.Abe
                    section.data(92).logicalSrcIdx = 117;
                    section.data(92).dtTransOffset = 189;

                    ;% UAM_Flight_control_B.pos_out
                    section.data(93).logicalSrcIdx = 121;
                    section.data(93).dtTransOffset = 192;

                    ;% UAM_Flight_control_B.vel_out
                    section.data(94).logicalSrcIdx = 122;
                    section.data(94).dtTransOffset = 195;

                    ;% UAM_Flight_control_B.Reshape
                    section.data(95).logicalSrcIdx = 131;
                    section.data(95).dtTransOffset = 198;

                    ;% UAM_Flight_control_B.UnaryMinus
                    section.data(96).logicalSrcIdx = 132;
                    section.data(96).dtTransOffset = 201;

                    ;% UAM_Flight_control_B.LAP
                    section.data(97).logicalSrcIdx = 133;
                    section.data(97).dtTransOffset = 202;

                    ;% UAM_Flight_control_B.TmpSignalConversionAtWaypointFo
                    section.data(98).logicalSrcIdx = 137;
                    section.data(98).dtTransOffset = 205;

                    ;% UAM_Flight_control_B.LAP_e
                    section.data(99).logicalSrcIdx = 138;
                    section.data(99).dtTransOffset = 209;

                    ;% UAM_Flight_control_B.course_o
                    section.data(100).logicalSrcIdx = 139;
                    section.data(100).dtTransOffset = 212;

                    ;% UAM_Flight_control_B.wps_h
                    section.data(101).logicalSrcIdx = 140;
                    section.data(101).dtTransOffset = 213;

                    ;% UAM_Flight_control_B.X_h
                    section.data(102).logicalSrcIdx = 141;
                    section.data(102).dtTransOffset = 219;

                    ;% UAM_Flight_control_B.Y_i
                    section.data(103).logicalSrcIdx = 142;
                    section.data(103).dtTransOffset = 220;

                    ;% UAM_Flight_control_B.Z_n
                    section.data(104).logicalSrcIdx = 143;
                    section.data(104).dtTransOffset = 221;

                    ;% UAM_Flight_control_B.Yaw_g
                    section.data(105).logicalSrcIdx = 144;
                    section.data(105).dtTransOffset = 222;

                    ;% UAM_Flight_control_B.Gain
                    section.data(106).logicalSrcIdx = 145;
                    section.data(106).dtTransOffset = 223;

                    ;% UAM_Flight_control_B.t_p
                    section.data(107).logicalSrcIdx = 146;
                    section.data(107).dtTransOffset = 226;

                    ;% UAM_Flight_control_B.e_q
                    section.data(108).logicalSrcIdx = 147;
                    section.data(108).dtTransOffset = 227;

                    ;% UAM_Flight_control_B.e_r
                    section.data(109).logicalSrcIdx = 148;
                    section.data(109).dtTransOffset = 228;

                    ;% UAM_Flight_control_B.Sum
                    section.data(110).logicalSrcIdx = 149;
                    section.data(110).dtTransOffset = 229;

                    ;% UAM_Flight_control_B.Gain_g
                    section.data(111).logicalSrcIdx = 150;
                    section.data(111).dtTransOffset = 230;

                    ;% UAM_Flight_control_B.l_x
                    section.data(112).logicalSrcIdx = 151;
                    section.data(112).dtTransOffset = 231;

                    ;% UAM_Flight_control_B.w1
                    section.data(113).logicalSrcIdx = 152;
                    section.data(113).dtTransOffset = 232;

                    ;% UAM_Flight_control_B.w2
                    section.data(114).logicalSrcIdx = 153;
                    section.data(114).dtTransOffset = 233;

                    ;% UAM_Flight_control_B.w3
                    section.data(115).logicalSrcIdx = 154;
                    section.data(115).dtTransOffset = 234;

                    ;% UAM_Flight_control_B.w4
                    section.data(116).logicalSrcIdx = 155;
                    section.data(116).dtTransOffset = 235;

                    ;% UAM_Flight_control_B.c1
                    section.data(117).logicalSrcIdx = 156;
                    section.data(117).dtTransOffset = 236;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreator_
                    section.data(118).logicalSrcIdx = 157;
                    section.data(118).dtTransOffset = 237;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_e
                    section.data(119).logicalSrcIdx = 158;
                    section.data(119).dtTransOffset = 238;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_d
                    section.data(120).logicalSrcIdx = 159;
                    section.data(120).dtTransOffset = 239;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_g
                    section.data(121).logicalSrcIdx = 160;
                    section.data(121).dtTransOffset = 240;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_n
                    section.data(122).logicalSrcIdx = 161;
                    section.data(122).dtTransOffset = 241;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_i
                    section.data(123).logicalSrcIdx = 162;
                    section.data(123).dtTransOffset = 242;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_dg
                    section.data(124).logicalSrcIdx = 163;
                    section.data(124).dtTransOffset = 243;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_a
                    section.data(125).logicalSrcIdx = 164;
                    section.data(125).dtTransOffset = 244;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_b
                    section.data(126).logicalSrcIdx = 165;
                    section.data(126).dtTransOffset = 245;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_j
                    section.data(127).logicalSrcIdx = 166;
                    section.data(127).dtTransOffset = 246;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_n2
                    section.data(128).logicalSrcIdx = 167;
                    section.data(128).dtTransOffset = 247;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_gx
                    section.data(129).logicalSrcIdx = 168;
                    section.data(129).dtTransOffset = 248;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ad
                    section.data(130).logicalSrcIdx = 169;
                    section.data(130).dtTransOffset = 249;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_bb
                    section.data(131).logicalSrcIdx = 170;
                    section.data(131).dtTransOffset = 250;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_p
                    section.data(132).logicalSrcIdx = 171;
                    section.data(132).dtTransOffset = 251;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_pd
                    section.data(133).logicalSrcIdx = 172;
                    section.data(133).dtTransOffset = 252;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_f
                    section.data(134).logicalSrcIdx = 173;
                    section.data(134).dtTransOffset = 253;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_by
                    section.data(135).logicalSrcIdx = 174;
                    section.data(135).dtTransOffset = 254;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_c
                    section.data(136).logicalSrcIdx = 175;
                    section.data(136).dtTransOffset = 255;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_du
                    section.data(137).logicalSrcIdx = 176;
                    section.data(137).dtTransOffset = 256;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_b5
                    section.data(138).logicalSrcIdx = 177;
                    section.data(138).dtTransOffset = 257;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_aw
                    section.data(139).logicalSrcIdx = 178;
                    section.data(139).dtTransOffset = 261;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_jx
                    section.data(140).logicalSrcIdx = 179;
                    section.data(140).dtTransOffset = 262;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_cv
                    section.data(141).logicalSrcIdx = 180;
                    section.data(141).dtTransOffset = 263;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_fp
                    section.data(142).logicalSrcIdx = 181;
                    section.data(142).dtTransOffset = 279;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_p2
                    section.data(143).logicalSrcIdx = 183;
                    section.data(143).dtTransOffset = 282;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_nm
                    section.data(144).logicalSrcIdx = 184;
                    section.data(144).dtTransOffset = 283;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_cg
                    section.data(145).logicalSrcIdx = 185;
                    section.data(145).dtTransOffset = 284;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_pr
                    section.data(146).logicalSrcIdx = 186;
                    section.data(146).dtTransOffset = 285;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_h
                    section.data(147).logicalSrcIdx = 187;
                    section.data(147).dtTransOffset = 286;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_f4
                    section.data(148).logicalSrcIdx = 188;
                    section.data(148).dtTransOffset = 287;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_k
                    section.data(149).logicalSrcIdx = 189;
                    section.data(149).dtTransOffset = 288;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_id
                    section.data(150).logicalSrcIdx = 190;
                    section.data(150).dtTransOffset = 289;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_gz
                    section.data(151).logicalSrcIdx = 191;
                    section.data(151).dtTransOffset = 290;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ex
                    section.data(152).logicalSrcIdx = 192;
                    section.data(152).dtTransOffset = 291;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_az
                    section.data(153).logicalSrcIdx = 193;
                    section.data(153).dtTransOffset = 292;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_f2
                    section.data(154).logicalSrcIdx = 194;
                    section.data(154).dtTransOffset = 293;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_km
                    section.data(155).logicalSrcIdx = 195;
                    section.data(155).dtTransOffset = 294;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_on
                    section.data(156).logicalSrcIdx = 196;
                    section.data(156).dtTransOffset = 295;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_da
                    section.data(157).logicalSrcIdx = 197;
                    section.data(157).dtTransOffset = 296;

                    ;% UAM_Flight_control_B.VectorConcatenate
                    section.data(158).logicalSrcIdx = 198;
                    section.data(158).dtTransOffset = 297;

                    ;% UAM_Flight_control_B.Gain1_p
                    section.data(159).logicalSrcIdx = 199;
                    section.data(159).dtTransOffset = 303;

                    ;% UAM_Flight_control_B.Saturation2
                    section.data(160).logicalSrcIdx = 200;
                    section.data(160).dtTransOffset = 304;

                    ;% UAM_Flight_control_B.Gain2
                    section.data(161).logicalSrcIdx = 201;
                    section.data(161).dtTransOffset = 305;

                    ;% UAM_Flight_control_B.Gain3
                    section.data(162).logicalSrcIdx = 202;
                    section.data(162).dtTransOffset = 306;

                    ;% UAM_Flight_control_B.Constant4
                    section.data(163).logicalSrcIdx = 203;
                    section.data(163).dtTransOffset = 307;

                    ;% UAM_Flight_control_B.TmpBufferAtConstant4Outport1
                    section.data(164).logicalSrcIdx = 204;
                    section.data(164).dtTransOffset = 308;

                    ;% UAM_Flight_control_B.Gain5
                    section.data(165).logicalSrcIdx = 205;
                    section.data(165).dtTransOffset = 309;

                    ;% UAM_Flight_control_B.dA
                    section.data(166).logicalSrcIdx = 206;
                    section.data(166).dtTransOffset = 310;

                    ;% UAM_Flight_control_B.dE
                    section.data(167).logicalSrcIdx = 207;
                    section.data(167).dtTransOffset = 311;

                    ;% UAM_Flight_control_B.dR
                    section.data(168).logicalSrcIdx = 208;
                    section.data(168).dtTransOffset = 312;

                    ;% UAM_Flight_control_B.dT
                    section.data(169).logicalSrcIdx = 209;
                    section.data(169).dtTransOffset = 313;

                    ;% UAM_Flight_control_B.dE_j
                    section.data(170).logicalSrcIdx = 211;
                    section.data(170).dtTransOffset = 314;

                    ;% UAM_Flight_control_B.Saturation
                    section.data(171).logicalSrcIdx = 212;
                    section.data(171).dtTransOffset = 315;

                    ;% UAM_Flight_control_B.Saturation2_m
                    section.data(172).logicalSrcIdx = 213;
                    section.data(172).dtTransOffset = 316;

                    ;% UAM_Flight_control_B.Product2
                    section.data(173).logicalSrcIdx = 215;
                    section.data(173).dtTransOffset = 317;

                    ;% UAM_Flight_control_B.cruise
                    section.data(174).logicalSrcIdx = 216;
                    section.data(174).dtTransOffset = 321;

                    ;% UAM_Flight_control_B.w1_j
                    section.data(175).logicalSrcIdx = 217;
                    section.data(175).dtTransOffset = 322;

                    ;% UAM_Flight_control_B.w2_i
                    section.data(176).logicalSrcIdx = 218;
                    section.data(176).dtTransOffset = 323;

                    ;% UAM_Flight_control_B.w4_g
                    section.data(177).logicalSrcIdx = 219;
                    section.data(177).dtTransOffset = 324;

                    ;% UAM_Flight_control_B.w3_o
                    section.data(178).logicalSrcIdx = 220;
                    section.data(178).dtTransOffset = 325;

                    ;% UAM_Flight_control_B.c1_i
                    section.data(179).logicalSrcIdx = 221;
                    section.data(179).dtTransOffset = 326;

                    ;% UAM_Flight_control_B.Switch1
                    section.data(180).logicalSrcIdx = 222;
                    section.data(180).dtTransOffset = 327;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_cv2
                    section.data(181).logicalSrcIdx = 223;
                    section.data(181).dtTransOffset = 333;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ez
                    section.data(182).logicalSrcIdx = 224;
                    section.data(182).dtTransOffset = 334;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_de
                    section.data(183).logicalSrcIdx = 225;
                    section.data(183).dtTransOffset = 335;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_gb
                    section.data(184).logicalSrcIdx = 226;
                    section.data(184).dtTransOffset = 336;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_nw
                    section.data(185).logicalSrcIdx = 227;
                    section.data(185).dtTransOffset = 337;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_i0
                    section.data(186).logicalSrcIdx = 228;
                    section.data(186).dtTransOffset = 338;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_dgz
                    section.data(187).logicalSrcIdx = 229;
                    section.data(187).dtTransOffset = 339;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ae
                    section.data(188).logicalSrcIdx = 230;
                    section.data(188).dtTransOffset = 340;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_bj
                    section.data(189).logicalSrcIdx = 231;
                    section.data(189).dtTransOffset = 341;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_jj
                    section.data(190).logicalSrcIdx = 232;
                    section.data(190).dtTransOffset = 342;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_n2x
                    section.data(191).logicalSrcIdx = 233;
                    section.data(191).dtTransOffset = 343;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_gx0
                    section.data(192).logicalSrcIdx = 234;
                    section.data(192).dtTransOffset = 344;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_adl
                    section.data(193).logicalSrcIdx = 235;
                    section.data(193).dtTransOffset = 345;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_bbr
                    section.data(194).logicalSrcIdx = 236;
                    section.data(194).dtTransOffset = 346;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_py
                    section.data(195).logicalSrcIdx = 237;
                    section.data(195).dtTransOffset = 347;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_pds
                    section.data(196).logicalSrcIdx = 238;
                    section.data(196).dtTransOffset = 348;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_fs
                    section.data(197).logicalSrcIdx = 239;
                    section.data(197).dtTransOffset = 349;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_by1
                    section.data(198).logicalSrcIdx = 240;
                    section.data(198).dtTransOffset = 350;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_cr
                    section.data(199).logicalSrcIdx = 241;
                    section.data(199).dtTransOffset = 351;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_duz
                    section.data(200).logicalSrcIdx = 242;
                    section.data(200).dtTransOffset = 352;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_b55
                    section.data(201).logicalSrcIdx = 243;
                    section.data(201).dtTransOffset = 353;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_awy
                    section.data(202).logicalSrcIdx = 244;
                    section.data(202).dtTransOffset = 357;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_jx3
                    section.data(203).logicalSrcIdx = 245;
                    section.data(203).dtTransOffset = 358;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_cvb
                    section.data(204).logicalSrcIdx = 246;
                    section.data(204).dtTransOffset = 359;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_fp5
                    section.data(205).logicalSrcIdx = 247;
                    section.data(205).dtTransOffset = 375;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_p2k
                    section.data(206).logicalSrcIdx = 249;
                    section.data(206).dtTransOffset = 378;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_nmo
                    section.data(207).logicalSrcIdx = 250;
                    section.data(207).dtTransOffset = 379;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_cga
                    section.data(208).logicalSrcIdx = 251;
                    section.data(208).dtTransOffset = 380;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_prh
                    section.data(209).logicalSrcIdx = 252;
                    section.data(209).dtTransOffset = 381;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_h4
                    section.data(210).logicalSrcIdx = 253;
                    section.data(210).dtTransOffset = 382;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_f4s
                    section.data(211).logicalSrcIdx = 254;
                    section.data(211).dtTransOffset = 383;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_kq
                    section.data(212).logicalSrcIdx = 255;
                    section.data(212).dtTransOffset = 384;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_idf
                    section.data(213).logicalSrcIdx = 256;
                    section.data(213).dtTransOffset = 385;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_gz0
                    section.data(214).logicalSrcIdx = 257;
                    section.data(214).dtTransOffset = 386;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_exi
                    section.data(215).logicalSrcIdx = 258;
                    section.data(215).dtTransOffset = 387;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_azp
                    section.data(216).logicalSrcIdx = 259;
                    section.data(216).dtTransOffset = 388;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_f2g
                    section.data(217).logicalSrcIdx = 260;
                    section.data(217).dtTransOffset = 389;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_kmx
                    section.data(218).logicalSrcIdx = 261;
                    section.data(218).dtTransOffset = 390;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_oni
                    section.data(219).logicalSrcIdx = 262;
                    section.data(219).dtTransOffset = 391;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_dax
                    section.data(220).logicalSrcIdx = 263;
                    section.data(220).dtTransOffset = 392;

                    ;% UAM_Flight_control_B.Gain1_h
                    section.data(221).logicalSrcIdx = 264;
                    section.data(221).dtTransOffset = 393;

                    ;% UAM_Flight_control_B.Gain2_a
                    section.data(222).logicalSrcIdx = 265;
                    section.data(222).dtTransOffset = 394;

                    ;% UAM_Flight_control_B.Gain3_n
                    section.data(223).logicalSrcIdx = 266;
                    section.data(223).dtTransOffset = 395;

                    ;% UAM_Flight_control_B.Gain4
                    section.data(224).logicalSrcIdx = 267;
                    section.data(224).dtTransOffset = 396;

                    ;% UAM_Flight_control_B.Add2
                    section.data(225).logicalSrcIdx = 268;
                    section.data(225).dtTransOffset = 397;

                    ;% UAM_Flight_control_B.Gain3_h
                    section.data(226).logicalSrcIdx = 269;
                    section.data(226).dtTransOffset = 398;

                    ;% UAM_Flight_control_B.Add1
                    section.data(227).logicalSrcIdx = 270;
                    section.data(227).dtTransOffset = 399;

                    ;% UAM_Flight_control_B.Gain2_l
                    section.data(228).logicalSrcIdx = 271;
                    section.data(228).dtTransOffset = 400;

                    ;% UAM_Flight_control_B.Add3
                    section.data(229).logicalSrcIdx = 272;
                    section.data(229).dtTransOffset = 401;

                    ;% UAM_Flight_control_B.Gain4_b
                    section.data(230).logicalSrcIdx = 273;
                    section.data(230).dtTransOffset = 402;

                    ;% UAM_Flight_control_B.Add
                    section.data(231).logicalSrcIdx = 274;
                    section.data(231).dtTransOffset = 403;

                    ;% UAM_Flight_control_B.Gain1_o
                    section.data(232).logicalSrcIdx = 275;
                    section.data(232).dtTransOffset = 404;

                    ;% UAM_Flight_control_B.m_out
                    section.data(233).logicalSrcIdx = 276;
                    section.data(233).dtTransOffset = 405;

                    ;% UAM_Flight_control_B.Merge1
                    section.data(234).logicalSrcIdx = 277;
                    section.data(234).dtTransOffset = 409;

                    ;% UAM_Flight_control_B.Merge_d5
                    section.data(235).logicalSrcIdx = 278;
                    section.data(235).dtTransOffset = 410;

                    ;% UAM_Flight_control_B.w_phi
                    section.data(236).logicalSrcIdx = 279;
                    section.data(236).dtTransOffset = 411;

                    ;% UAM_Flight_control_B.w_theta
                    section.data(237).logicalSrcIdx = 280;
                    section.data(237).dtTransOffset = 412;

                    ;% UAM_Flight_control_B.w_psi
                    section.data(238).logicalSrcIdx = 281;
                    section.data(238).dtTransOffset = 413;

                    ;% UAM_Flight_control_B.w_z
                    section.data(239).logicalSrcIdx = 282;
                    section.data(239).dtTransOffset = 414;

                    ;% UAM_Flight_control_B.Saturation_g
                    section.data(240).logicalSrcIdx = 283;
                    section.data(240).dtTransOffset = 415;

                    ;% UAM_Flight_control_B.Saturation1
                    section.data(241).logicalSrcIdx = 284;
                    section.data(241).dtTransOffset = 416;

                    ;% UAM_Flight_control_B.Sum3
                    section.data(242).logicalSrcIdx = 286;
                    section.data(242).dtTransOffset = 417;

                    ;% UAM_Flight_control_B.Product
                    section.data(243).logicalSrcIdx = 287;
                    section.data(243).dtTransOffset = 418;

                    ;% UAM_Flight_control_B.AltHold
                    section.data(244).logicalSrcIdx = 289;
                    section.data(244).dtTransOffset = 419;

                    ;% UAM_Flight_control_B.altitude_k
                    section.data(245).logicalSrcIdx = 291;
                    section.data(245).dtTransOffset = 420;

                    ;% UAM_Flight_control_B.PitchSPMerge
                    section.data(246).logicalSrcIdx = 292;
                    section.data(246).dtTransOffset = 421;

                    ;% UAM_Flight_control_B.course_b
                    section.data(247).logicalSrcIdx = 293;
                    section.data(247).dtTransOffset = 422;

                    ;% UAM_Flight_control_B.L1
                    section.data(248).logicalSrcIdx = 294;
                    section.data(248).dtTransOffset = 423;

                    ;% UAM_Flight_control_B.RollSPMerge
                    section.data(249).logicalSrcIdx = 295;
                    section.data(249).dtTransOffset = 424;

                    ;% UAM_Flight_control_B.ActuatordTMerge
                    section.data(250).logicalSrcIdx = 296;
                    section.data(250).dtTransOffset = 425;

                    ;% UAM_Flight_control_B.Merge_p
                    section.data(251).logicalSrcIdx = 297;
                    section.data(251).dtTransOffset = 426;

                    ;% UAM_Flight_control_B.Saturation_o
                    section.data(252).logicalSrcIdx = 300;
                    section.data(252).dtTransOffset = 429;

                    ;% UAM_Flight_control_B.Saturation1_l
                    section.data(253).logicalSrcIdx = 301;
                    section.data(253).dtTransOffset = 430;

                    ;% UAM_Flight_control_B.Saturation_e
                    section.data(254).logicalSrcIdx = 302;
                    section.data(254).dtTransOffset = 431;

                    ;% UAM_Flight_control_B.Saturation_m
                    section.data(255).logicalSrcIdx = 303;
                    section.data(255).dtTransOffset = 432;

                    ;% UAM_Flight_control_B.Saturation_b
                    section.data(256).logicalSrcIdx = 304;
                    section.data(256).dtTransOffset = 433;

                    ;% UAM_Flight_control_B.Saturation_m2
                    section.data(257).logicalSrcIdx = 305;
                    section.data(257).dtTransOffset = 434;

                    ;% UAM_Flight_control_B.Saturation_k
                    section.data(258).logicalSrcIdx = 306;
                    section.data(258).dtTransOffset = 435;

                    ;% UAM_Flight_control_B.ClimbRateSPMerge
                    section.data(259).logicalSrcIdx = 308;
                    section.data(259).dtTransOffset = 436;

                    ;% UAM_Flight_control_B.UnaryMinus_h
                    section.data(260).logicalSrcIdx = 309;
                    section.data(260).dtTransOffset = 437;

                    ;% UAM_Flight_control_B.Saturation_md
                    section.data(261).logicalSrcIdx = 310;
                    section.data(261).dtTransOffset = 438;

                    ;% UAM_Flight_control_B.UnaryMinus_f
                    section.data(262).logicalSrcIdx = 312;
                    section.data(262).dtTransOffset = 439;

                    ;% UAM_Flight_control_B.Saturation_d
                    section.data(263).logicalSrcIdx = 313;
                    section.data(263).dtTransOffset = 440;

                    ;% UAM_Flight_control_B.Merge2
                    section.data(264).logicalSrcIdx = 314;
                    section.data(264).dtTransOffset = 441;

                    ;% UAM_Flight_control_B.Gain_a
                    section.data(265).logicalSrcIdx = 315;
                    section.data(265).dtTransOffset = 442;

                    ;% UAM_Flight_control_B.RefRP
                    section.data(266).logicalSrcIdx = 316;
                    section.data(266).dtTransOffset = 445;

                    ;% UAM_Flight_control_B.Sum_n
                    section.data(267).logicalSrcIdx = 317;
                    section.data(267).dtTransOffset = 447;

                    ;% UAM_Flight_control_B.Sum_o
                    section.data(268).logicalSrcIdx = 318;
                    section.data(268).dtTransOffset = 448;

                    ;% UAM_Flight_control_B.Saturation5
                    section.data(269).logicalSrcIdx = 319;
                    section.data(269).dtTransOffset = 449;

                    ;% UAM_Flight_control_B.w_phi_d
                    section.data(270).logicalSrcIdx = 320;
                    section.data(270).dtTransOffset = 450;

                    ;% UAM_Flight_control_B.w_theta_i
                    section.data(271).logicalSrcIdx = 321;
                    section.data(271).dtTransOffset = 451;

                    ;% UAM_Flight_control_B.w_psi_f
                    section.data(272).logicalSrcIdx = 322;
                    section.data(272).dtTransOffset = 452;

                    ;% UAM_Flight_control_B.w_z_c
                    section.data(273).logicalSrcIdx = 323;
                    section.data(273).dtTransOffset = 453;

                    ;% UAM_Flight_control_B.In1
                    section.data(274).logicalSrcIdx = 324;
                    section.data(274).dtTransOffset = 454;

                    ;% UAM_Flight_control_B.Add_c
                    section.data(275).logicalSrcIdx = 325;
                    section.data(275).dtTransOffset = 455;

                    ;% UAM_Flight_control_B.Switch2
                    section.data(276).logicalSrcIdx = 326;
                    section.data(276).dtTransOffset = 456;

                    ;% UAM_Flight_control_B.Switch1_n
                    section.data(277).logicalSrcIdx = 327;
                    section.data(277).dtTransOffset = 457;

                    ;% UAM_Flight_control_B.Add_i
                    section.data(278).logicalSrcIdx = 328;
                    section.data(278).dtTransOffset = 458;

                    ;% UAM_Flight_control_B.Switch
                    section.data(279).logicalSrcIdx = 329;
                    section.data(279).dtTransOffset = 459;

                    ;% UAM_Flight_control_B.Saturation_kf
                    section.data(280).logicalSrcIdx = 330;
                    section.data(280).dtTransOffset = 460;

                    ;% UAM_Flight_control_B.Saturation1_k
                    section.data(281).logicalSrcIdx = 331;
                    section.data(281).dtTransOffset = 461;

                    ;% UAM_Flight_control_B.Add_h
                    section.data(282).logicalSrcIdx = 332;
                    section.data(282).dtTransOffset = 462;

                    ;% UAM_Flight_control_B.Switch1_n5
                    section.data(283).logicalSrcIdx = 333;
                    section.data(283).dtTransOffset = 463;

                    ;% UAM_Flight_control_B.Add_o
                    section.data(284).logicalSrcIdx = 334;
                    section.data(284).dtTransOffset = 464;

                    ;% UAM_Flight_control_B.Saturation_a
                    section.data(285).logicalSrcIdx = 335;
                    section.data(285).dtTransOffset = 465;

                    ;% UAM_Flight_control_B.Saturation_ke
                    section.data(286).logicalSrcIdx = 336;
                    section.data(286).dtTransOffset = 466;

                    ;% UAM_Flight_control_B.XRef
                    section.data(287).logicalSrcIdx = 338;
                    section.data(287).dtTransOffset = 467;

                    ;% UAM_Flight_control_B.YRef
                    section.data(288).logicalSrcIdx = 339;
                    section.data(288).dtTransOffset = 468;

                    ;% UAM_Flight_control_B.Gain_c
                    section.data(289).logicalSrcIdx = 340;
                    section.data(289).dtTransOffset = 469;

                    ;% UAM_Flight_control_B.UnitDelay
                    section.data(290).logicalSrcIdx = 341;
                    section.data(290).dtTransOffset = 470;

                    ;% UAM_Flight_control_B.Switch1_nh
                    section.data(291).logicalSrcIdx = 342;
                    section.data(291).dtTransOffset = 471;

                    ;% UAM_Flight_control_B.ProportionalGain
                    section.data(292).logicalSrcIdx = 343;
                    section.data(292).dtTransOffset = 472;

                    ;% UAM_Flight_control_B.Gain1_i
                    section.data(293).logicalSrcIdx = 344;
                    section.data(293).dtTransOffset = 473;

                    ;% UAM_Flight_control_B.Sum3_b
                    section.data(294).logicalSrcIdx = 345;
                    section.data(294).dtTransOffset = 474;

                    ;% UAM_Flight_control_B.Product_p
                    section.data(295).logicalSrcIdx = 346;
                    section.data(295).dtTransOffset = 475;

                    ;% UAM_Flight_control_B.y_o
                    section.data(296).logicalSrcIdx = 347;
                    section.data(296).dtTransOffset = 476;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_cv2z
                    section.data(297).logicalSrcIdx = 348;
                    section.data(297).dtTransOffset = 477;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_ezp
                    section.data(298).logicalSrcIdx = 349;
                    section.data(298).dtTransOffset = 478;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_dec
                    section.data(299).logicalSrcIdx = 350;
                    section.data(299).dtTransOffset = 479;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_gbt
                    section.data(300).logicalSrcIdx = 351;
                    section.data(300).dtTransOffset = 480;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_nw2
                    section.data(301).logicalSrcIdx = 352;
                    section.data(301).dtTransOffset = 481;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_i0g
                    section.data(302).logicalSrcIdx = 353;
                    section.data(302).dtTransOffset = 482;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_dgzi
                    section.data(303).logicalSrcIdx = 354;
                    section.data(303).dtTransOffset = 483;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_ae0
                    section.data(304).logicalSrcIdx = 355;
                    section.data(304).dtTransOffset = 484;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_bjh
                    section.data(305).logicalSrcIdx = 356;
                    section.data(305).dtTransOffset = 485;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_jjd
                    section.data(306).logicalSrcIdx = 357;
                    section.data(306).dtTransOffset = 486;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_n2x4
                    section.data(307).logicalSrcIdx = 358;
                    section.data(307).dtTransOffset = 487;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_gx0x
                    section.data(308).logicalSrcIdx = 359;
                    section.data(308).dtTransOffset = 488;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_adlp
                    section.data(309).logicalSrcIdx = 360;
                    section.data(309).dtTransOffset = 489;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_bbr4
                    section.data(310).logicalSrcIdx = 361;
                    section.data(310).dtTransOffset = 490;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_pyg
                    section.data(311).logicalSrcIdx = 362;
                    section.data(311).dtTransOffset = 491;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_pdsb
                    section.data(312).logicalSrcIdx = 363;
                    section.data(312).dtTransOffset = 492;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_fsn
                    section.data(313).logicalSrcIdx = 364;
                    section.data(313).dtTransOffset = 493;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_by1n
                    section.data(314).logicalSrcIdx = 365;
                    section.data(314).dtTransOffset = 494;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_cr0
                    section.data(315).logicalSrcIdx = 366;
                    section.data(315).dtTransOffset = 495;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_duzz
                    section.data(316).logicalSrcIdx = 367;
                    section.data(316).dtTransOffset = 496;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_b55m
                    section.data(317).logicalSrcIdx = 368;
                    section.data(317).dtTransOffset = 497;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_awya
                    section.data(318).logicalSrcIdx = 369;
                    section.data(318).dtTransOffset = 501;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_jx3i
                    section.data(319).logicalSrcIdx = 370;
                    section.data(319).dtTransOffset = 502;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_cvbt
                    section.data(320).logicalSrcIdx = 371;
                    section.data(320).dtTransOffset = 503;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_fp5m
                    section.data(321).logicalSrcIdx = 372;
                    section.data(321).dtTransOffset = 519;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_p2kv
                    section.data(322).logicalSrcIdx = 374;
                    section.data(322).dtTransOffset = 522;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_nmoe
                    section.data(323).logicalSrcIdx = 375;
                    section.data(323).dtTransOffset = 523;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_cgay
                    section.data(324).logicalSrcIdx = 376;
                    section.data(324).dtTransOffset = 524;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_prhp
                    section.data(325).logicalSrcIdx = 377;
                    section.data(325).dtTransOffset = 525;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_h4h
                    section.data(326).logicalSrcIdx = 378;
                    section.data(326).dtTransOffset = 526;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_f4ss
                    section.data(327).logicalSrcIdx = 379;
                    section.data(327).dtTransOffset = 527;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_kqf
                    section.data(328).logicalSrcIdx = 380;
                    section.data(328).dtTransOffset = 528;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_idfy
                    section.data(329).logicalSrcIdx = 381;
                    section.data(329).dtTransOffset = 529;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_gz0w
                    section.data(330).logicalSrcIdx = 382;
                    section.data(330).dtTransOffset = 530;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_exia
                    section.data(331).logicalSrcIdx = 383;
                    section.data(331).dtTransOffset = 531;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_azpg
                    section.data(332).logicalSrcIdx = 384;
                    section.data(332).dtTransOffset = 532;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_f2gs
                    section.data(333).logicalSrcIdx = 385;
                    section.data(333).dtTransOffset = 533;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_kmxi
                    section.data(334).logicalSrcIdx = 386;
                    section.data(334).dtTransOffset = 534;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_oniv
                    section.data(335).logicalSrcIdx = 387;
                    section.data(335).dtTransOffset = 535;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_daxi
                    section.data(336).logicalSrcIdx = 388;
                    section.data(336).dtTransOffset = 536;

                    ;% UAM_Flight_control_B.VectorConcatenate_c
                    section.data(337).logicalSrcIdx = 389;
                    section.data(337).dtTransOffset = 537;

                    ;% UAM_Flight_control_B.Constant
                    section.data(338).logicalSrcIdx = 390;
                    section.data(338).dtTransOffset = 543;

                    ;% UAM_Flight_control_B.TmpSignalConversionAtMatrixMult
                    section.data(339).logicalSrcIdx = 391;
                    section.data(339).dtTransOffset = 559;

                    ;% UAM_Flight_control_B.m_l
                    section.data(340).logicalSrcIdx = 392;
                    section.data(340).dtTransOffset = 563;

                    ;% UAM_Flight_control_B.TmpBufferAtConstant4Outport1_k
                    section.data(341).logicalSrcIdx = 393;
                    section.data(341).dtTransOffset = 567;

                    ;% UAM_Flight_control_B.m_out_b
                    section.data(342).logicalSrcIdx = 394;
                    section.data(342).dtTransOffset = 568;

                    ;% UAM_Flight_control_B.dA_n
                    section.data(343).logicalSrcIdx = 395;
                    section.data(343).dtTransOffset = 572;

                    ;% UAM_Flight_control_B.dE_a
                    section.data(344).logicalSrcIdx = 396;
                    section.data(344).dtTransOffset = 573;

                    ;% UAM_Flight_control_B.dR_g
                    section.data(345).logicalSrcIdx = 397;
                    section.data(345).dtTransOffset = 574;

                    ;% UAM_Flight_control_B.dT_i
                    section.data(346).logicalSrcIdx = 398;
                    section.data(346).dtTransOffset = 575;

                    ;% UAM_Flight_control_B.MatrixMultiply
                    section.data(347).logicalSrcIdx = 399;
                    section.data(347).dtTransOffset = 576;

                    ;% UAM_Flight_control_B.Saturation2_n
                    section.data(348).logicalSrcIdx = 400;
                    section.data(348).dtTransOffset = 578;

            nTotData = nTotData + section.nData;
            sigMap.sections(10) = section;
            clear section

            section.nData     = 55;
            section.data(55)  = dumData; %prealloc

                    ;% UAM_Flight_control_B.target_roll
                    section.data(1).logicalSrcIdx = 401;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_B.target_pitch
                    section.data(2).logicalSrcIdx = 402;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_B.target_yaw
                    section.data(3).logicalSrcIdx = 403;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_B.target_alt
                    section.data(4).logicalSrcIdx = 404;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_B.dist_n
                    section.data(5).logicalSrcIdx = 405;
                    section.data(5).dtTransOffset = 4;

                    ;% UAM_Flight_control_B.dist_e
                    section.data(6).logicalSrcIdx = 406;
                    section.data(6).dtTransOffset = 5;

                    ;% UAM_Flight_control_B.dist_d
                    section.data(7).logicalSrcIdx = 407;
                    section.data(7).dtTransOffset = 6;

                    ;% UAM_Flight_control_B.roll_rate
                    section.data(8).logicalSrcIdx = 408;
                    section.data(8).dtTransOffset = 7;

                    ;% UAM_Flight_control_B.pitch_rate
                    section.data(9).logicalSrcIdx = 409;
                    section.data(9).dtTransOffset = 8;

                    ;% UAM_Flight_control_B.yaw_rate
                    section.data(10).logicalSrcIdx = 410;
                    section.data(10).dtTransOffset = 9;

                    ;% UAM_Flight_control_B.target_x
                    section.data(11).logicalSrcIdx = 411;
                    section.data(11).dtTransOffset = 10;

                    ;% UAM_Flight_control_B.target_y
                    section.data(12).logicalSrcIdx = 412;
                    section.data(12).dtTransOffset = 11;

                    ;% UAM_Flight_control_B.target_z
                    section.data(13).logicalSrcIdx = 413;
                    section.data(13).dtTransOffset = 12;

                    ;% UAM_Flight_control_B.target_x_a
                    section.data(14).logicalSrcIdx = 414;
                    section.data(14).dtTransOffset = 13;

                    ;% UAM_Flight_control_B.target_y_p
                    section.data(15).logicalSrcIdx = 415;
                    section.data(15).dtTransOffset = 14;

                    ;% UAM_Flight_control_B.target_z_m
                    section.data(16).logicalSrcIdx = 416;
                    section.data(16).dtTransOffset = 15;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ba
                    section.data(17).logicalSrcIdx = 417;
                    section.data(17).dtTransOffset = 16;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ed
                    section.data(18).logicalSrcIdx = 418;
                    section.data(18).dtTransOffset = 17;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_nl
                    section.data(19).logicalSrcIdx = 419;
                    section.data(19).dtTransOffset = 18;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_kb
                    section.data(20).logicalSrcIdx = 420;
                    section.data(20).dtTransOffset = 19;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_m
                    section.data(21).logicalSrcIdx = 421;
                    section.data(21).dtTransOffset = 20;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ps
                    section.data(22).logicalSrcIdx = 422;
                    section.data(22).dtTransOffset = 21;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_aj
                    section.data(23).logicalSrcIdx = 423;
                    section.data(23).dtTransOffset = 22;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_hw
                    section.data(24).logicalSrcIdx = 424;
                    section.data(24).dtTransOffset = 23;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_pg
                    section.data(25).logicalSrcIdx = 425;
                    section.data(25).dtTransOffset = 24;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_mq
                    section.data(26).logicalSrcIdx = 426;
                    section.data(26).dtTransOffset = 25;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ke
                    section.data(27).logicalSrcIdx = 427;
                    section.data(27).dtTransOffset = 26;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ah
                    section.data(28).logicalSrcIdx = 428;
                    section.data(28).dtTransOffset = 27;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_e1
                    section.data(29).logicalSrcIdx = 429;
                    section.data(29).dtTransOffset = 28;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_baw
                    section.data(30).logicalSrcIdx = 430;
                    section.data(30).dtTransOffset = 29;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_edg
                    section.data(31).logicalSrcIdx = 431;
                    section.data(31).dtTransOffset = 30;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_nly
                    section.data(32).logicalSrcIdx = 432;
                    section.data(32).dtTransOffset = 31;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_kbh
                    section.data(33).logicalSrcIdx = 433;
                    section.data(33).dtTransOffset = 32;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_me
                    section.data(34).logicalSrcIdx = 434;
                    section.data(34).dtTransOffset = 33;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_ps2
                    section.data(35).logicalSrcIdx = 435;
                    section.data(35).dtTransOffset = 34;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_ajj
                    section.data(36).logicalSrcIdx = 436;
                    section.data(36).dtTransOffset = 35;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_hwn
                    section.data(37).logicalSrcIdx = 437;
                    section.data(37).dtTransOffset = 36;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_pgb
                    section.data(38).logicalSrcIdx = 438;
                    section.data(38).dtTransOffset = 37;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_mqv
                    section.data(39).logicalSrcIdx = 439;
                    section.data(39).dtTransOffset = 38;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_kew
                    section.data(40).logicalSrcIdx = 440;
                    section.data(40).dtTransOffset = 39;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_ahl
                    section.data(41).logicalSrcIdx = 441;
                    section.data(41).dtTransOffset = 40;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_e1u
                    section.data(42).logicalSrcIdx = 442;
                    section.data(42).dtTransOffset = 41;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_bawm
                    section.data(43).logicalSrcIdx = 443;
                    section.data(43).dtTransOffset = 42;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_edgh
                    section.data(44).logicalSrcIdx = 444;
                    section.data(44).dtTransOffset = 43;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_nlya
                    section.data(45).logicalSrcIdx = 445;
                    section.data(45).dtTransOffset = 44;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_kbhl
                    section.data(46).logicalSrcIdx = 446;
                    section.data(46).dtTransOffset = 45;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_mey
                    section.data(47).logicalSrcIdx = 447;
                    section.data(47).dtTransOffset = 46;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_ps2n
                    section.data(48).logicalSrcIdx = 448;
                    section.data(48).dtTransOffset = 47;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_ajjw
                    section.data(49).logicalSrcIdx = 449;
                    section.data(49).dtTransOffset = 48;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_hwn1
                    section.data(50).logicalSrcIdx = 450;
                    section.data(50).dtTransOffset = 49;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_pgbn
                    section.data(51).logicalSrcIdx = 451;
                    section.data(51).dtTransOffset = 50;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_mqvj
                    section.data(52).logicalSrcIdx = 452;
                    section.data(52).dtTransOffset = 51;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_kewq
                    section.data(53).logicalSrcIdx = 453;
                    section.data(53).dtTransOffset = 52;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_ahl1
                    section.data(54).logicalSrcIdx = 454;
                    section.data(54).dtTransOffset = 53;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_e1ub
                    section.data(55).logicalSrcIdx = 455;
                    section.data(55).dtTransOffset = 54;

            nTotData = nTotData + section.nData;
            sigMap.sections(11) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% UAM_Flight_control_B.FlightMode
                    section.data(1).logicalSrcIdx = 456;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_B.Hover_p
                    section.data(2).logicalSrcIdx = 457;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_B.flightMode
                    section.data(3).logicalSrcIdx = 458;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_B.Constant2
                    section.data(4).logicalSrcIdx = 459;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_B.FlightMode_c
                    section.data(5).logicalSrcIdx = 460;
                    section.data(5).dtTransOffset = 4;

                    ;% UAM_Flight_control_B.Hover_i
                    section.data(6).logicalSrcIdx = 461;
                    section.data(6).dtTransOffset = 5;

                    ;% UAM_Flight_control_B.flightMode_c
                    section.data(7).logicalSrcIdx = 462;
                    section.data(7).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            sigMap.sections(12) = section;
            clear section

            section.nData     = 20;
            section.data(20)  = dumData; %prealloc

                    ;% UAM_Flight_control_B.voltage
                    section.data(1).logicalSrcIdx = 464;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_B.current
                    section.data(2).logicalSrcIdx = 465;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_B.soc
                    section.data(3).logicalSrcIdx = 466;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_B.temperature
                    section.data(4).logicalSrcIdx = 467;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_B.soh
                    section.data(5).logicalSrcIdx = 468;
                    section.data(5).dtTransOffset = 4;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_l
                    section.data(6).logicalSrcIdx = 469;
                    section.data(6).dtTransOffset = 5;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_bk
                    section.data(7).logicalSrcIdx = 470;
                    section.data(7).dtTransOffset = 6;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ir
                    section.data(8).logicalSrcIdx = 471;
                    section.data(8).dtTransOffset = 7;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_exu
                    section.data(9).logicalSrcIdx = 472;
                    section.data(9).dtTransOffset = 8;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ou
                    section.data(10).logicalSrcIdx = 473;
                    section.data(10).dtTransOffset = 9;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_l5
                    section.data(11).logicalSrcIdx = 474;
                    section.data(11).dtTransOffset = 10;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_bkn
                    section.data(12).logicalSrcIdx = 475;
                    section.data(12).dtTransOffset = 11;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_irm
                    section.data(13).logicalSrcIdx = 476;
                    section.data(13).dtTransOffset = 12;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_exub
                    section.data(14).logicalSrcIdx = 477;
                    section.data(14).dtTransOffset = 13;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_ouu
                    section.data(15).logicalSrcIdx = 478;
                    section.data(15).dtTransOffset = 14;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_l5c
                    section.data(16).logicalSrcIdx = 479;
                    section.data(16).dtTransOffset = 15;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_bkn5
                    section.data(17).logicalSrcIdx = 480;
                    section.data(17).dtTransOffset = 16;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_irme
                    section.data(18).logicalSrcIdx = 481;
                    section.data(18).dtTransOffset = 17;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCr_exubp
                    section.data(19).logicalSrcIdx = 482;
                    section.data(19).dtTransOffset = 18;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_ouuy
                    section.data(20).logicalSrcIdx = 483;
                    section.data(20).dtTransOffset = 19;

            nTotData = nTotData + section.nData;
            sigMap.sections(13) = section;
            clear section

            section.nData     = 35;
            section.data(35)  = dumData; %prealloc

                    ;% UAM_Flight_control_B.mode
                    section.data(1).logicalSrcIdx = 484;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_B.gps_num_sv
                    section.data(2).logicalSrcIdx = 485;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_B.gcs_link
                    section.data(3).logicalSrcIdx = 486;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_B.rc_link
                    section.data(4).logicalSrcIdx = 487;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_B.flight_mode
                    section.data(5).logicalSrcIdx = 488;
                    section.data(5).dtTransOffset = 4;

                    ;% UAM_Flight_control_B.Status
                    section.data(6).logicalSrcIdx = 489;
                    section.data(6).dtTransOffset = 5;

                    ;% UAM_Flight_control_B.mode_j
                    section.data(7).logicalSrcIdx = 490;
                    section.data(7).dtTransOffset = 6;

                    ;% UAM_Flight_control_B.gps_fix
                    section.data(8).logicalSrcIdx = 491;
                    section.data(8).dtTransOffset = 7;

                    ;% UAM_Flight_control_B.gps_valid
                    section.data(9).logicalSrcIdx = 492;
                    section.data(9).dtTransOffset = 8;

                    ;% UAM_Flight_control_B.baro_valid
                    section.data(10).logicalSrcIdx = 493;
                    section.data(10).dtTransOffset = 9;

                    ;% UAM_Flight_control_B.Status_l
                    section.data(11).logicalSrcIdx = 494;
                    section.data(11).dtTransOffset = 10;

                    ;% UAM_Flight_control_B.WaypointFollower_o4
                    section.data(12).logicalSrcIdx = 495;
                    section.data(12).dtTransOffset = 11;

                    ;% UAM_Flight_control_B.WaypointFollower_o4_j
                    section.data(13).logicalSrcIdx = 496;
                    section.data(13).dtTransOffset = 12;

                    ;% UAM_Flight_control_B.WaypointFollower_o5
                    section.data(14).logicalSrcIdx = 497;
                    section.data(14).dtTransOffset = 13;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_dq
                    section.data(15).logicalSrcIdx = 498;
                    section.data(15).dtTransOffset = 14;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_k5
                    section.data(16).logicalSrcIdx = 499;
                    section.data(16).dtTransOffset = 15;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_od
                    section.data(17).logicalSrcIdx = 500;
                    section.data(17).dtTransOffset = 16;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_a2
                    section.data(18).logicalSrcIdx = 501;
                    section.data(18).dtTransOffset = 17;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_em
                    section.data(19).logicalSrcIdx = 502;
                    section.data(19).dtTransOffset = 18;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_dn
                    section.data(20).logicalSrcIdx = 503;
                    section.data(20).dtTransOffset = 19;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_mm
                    section.data(21).logicalSrcIdx = 504;
                    section.data(21).dtTransOffset = 20;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_dq0
                    section.data(22).logicalSrcIdx = 505;
                    section.data(22).dtTransOffset = 21;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_k55
                    section.data(23).logicalSrcIdx = 506;
                    section.data(23).dtTransOffset = 22;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_odd
                    section.data(24).logicalSrcIdx = 507;
                    section.data(24).dtTransOffset = 23;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_a2g
                    section.data(25).logicalSrcIdx = 508;
                    section.data(25).dtTransOffset = 24;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_ema
                    section.data(26).logicalSrcIdx = 509;
                    section.data(26).dtTransOffset = 25;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_dnv
                    section.data(27).logicalSrcIdx = 510;
                    section.data(27).dtTransOffset = 26;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_mm3
                    section.data(28).logicalSrcIdx = 511;
                    section.data(28).dtTransOffset = 27;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_dq0y
                    section.data(29).logicalSrcIdx = 512;
                    section.data(29).dtTransOffset = 28;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_k55z
                    section.data(30).logicalSrcIdx = 513;
                    section.data(30).dtTransOffset = 29;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_odds
                    section.data(31).logicalSrcIdx = 514;
                    section.data(31).dtTransOffset = 30;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_a2gj
                    section.data(32).logicalSrcIdx = 515;
                    section.data(32).dtTransOffset = 31;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_emaa
                    section.data(33).logicalSrcIdx = 516;
                    section.data(33).dtTransOffset = 32;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_dnvz
                    section.data(34).logicalSrcIdx = 517;
                    section.data(34).dtTransOffset = 33;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_mm34
                    section.data(35).logicalSrcIdx = 518;
                    section.data(35).dtTransOffset = 34;

            nTotData = nTotData + section.nData;
            sigMap.sections(14) = section;
            clear section

            section.nData     = 15;
            section.data(15)  = dumData; %prealloc

                    ;% UAM_Flight_control_B.DataTypeConversion
                    section.data(1).logicalSrcIdx = 519;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_B.Compare
                    section.data(2).logicalSrcIdx = 520;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_B.Compare_o
                    section.data(3).logicalSrcIdx = 521;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_B.Constant_l
                    section.data(4).logicalSrcIdx = 522;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_B.XYZ_Valid
                    section.data(5).logicalSrcIdx = 523;
                    section.data(5).dtTransOffset = 4;

                    ;% UAM_Flight_control_B.AND1
                    section.data(6).logicalSrcIdx = 524;
                    section.data(6).dtTransOffset = 5;

                    ;% UAM_Flight_control_B.OR1
                    section.data(7).logicalSrcIdx = 525;
                    section.data(7).dtTransOffset = 6;

                    ;% UAM_Flight_control_B.XYZ_nan
                    section.data(8).logicalSrcIdx = 526;
                    section.data(8).dtTransOffset = 7;

                    ;% UAM_Flight_control_B.OR
                    section.data(9).logicalSrcIdx = 527;
                    section.data(9).dtTransOffset = 8;

                    ;% UAM_Flight_control_B.AND
                    section.data(10).logicalSrcIdx = 528;
                    section.data(10).dtTransOffset = 9;

                    ;% UAM_Flight_control_B.Compare_m
                    section.data(11).logicalSrcIdx = 529;
                    section.data(11).dtTransOffset = 10;

                    ;% UAM_Flight_control_B.FixPtRelationalOperator
                    section.data(12).logicalSrcIdx = 530;
                    section.data(12).dtTransOffset = 11;

                    ;% UAM_Flight_control_B.FixPtRelationalOperator_d
                    section.data(13).logicalSrcIdx = 531;
                    section.data(13).dtTransOffset = 12;

                    ;% UAM_Flight_control_B.OR_j
                    section.data(14).logicalSrcIdx = 532;
                    section.data(14).dtTransOffset = 13;

                    ;% UAM_Flight_control_B.OR_e
                    section.data(15).logicalSrcIdx = 533;
                    section.data(15).dtTransOffset = 14;

            nTotData = nTotData + section.nData;
            sigMap.sections(15) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_B.WaypointFollower_ni.LAP
                    section.data(1).logicalSrcIdx = 534;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(16) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_B.WaypointFollower_n.LAP
                    section.data(1).logicalSrcIdx = 535;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(17) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 66;
        sectIdxOffset = 17;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (UAM_Flight_control_DW)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.obj
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.obj_d
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.obj_l
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.obj_c
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.obj_j
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.obj_cg
                    section.data(1).logicalSrcIdx = 5;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_DW.obj_jc
                    section.data(2).logicalSrcIdx = 6;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.UnitDelay_3_DSTATE
                    section.data(1).logicalSrcIdx = 7;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_DW.UnitDelay_2_DSTATE
                    section.data(2).logicalSrcIdx = 8;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.UnitDelay1_7_DSTATE
                    section.data(1).logicalSrcIdx = 9;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.UnitDelay_6_DSTATE
                    section.data(1).logicalSrcIdx = 10;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_DW.UnitDelay_6_DSTATE_h
                    section.data(2).logicalSrcIdx = 11;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_DW.UnitDelay_6_DSTATE_b
                    section.data(3).logicalSrcIdx = 12;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(9) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.UnitDelay_7_DSTATE
                    section.data(1).logicalSrcIdx = 13;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_DW.UnitDelay_7_DSTATE_i
                    section.data(2).logicalSrcIdx = 14;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_DW.UnitDelay_7_DSTATE_b
                    section.data(3).logicalSrcIdx = 15;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(10) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.RateTransition1_13_Buffer
                    section.data(1).logicalSrcIdx = 16;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(11) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.UnitDelay_5_DSTATE
                    section.data(1).logicalSrcIdx = 17;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_DW.UnitDelay_5_DSTATE_p
                    section.data(2).logicalSrcIdx = 18;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_DW.UnitDelay_5_DSTATE_h
                    section.data(3).logicalSrcIdx = 19;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(12) = section;
            clear section

            section.nData     = 97;
            section.data(97)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.UnitDelay6_DSTATE
                    section.data(1).logicalSrcIdx = 20;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_DW.UnitDelay7_DSTATE
                    section.data(2).logicalSrcIdx = 21;
                    section.data(2).dtTransOffset = 4;

                    ;% UAM_Flight_control_DW.UnitDelay8_DSTATE
                    section.data(3).logicalSrcIdx = 22;
                    section.data(3).dtTransOffset = 7;

                    ;% UAM_Flight_control_DW.UnitDelay9_DSTATE
                    section.data(4).logicalSrcIdx = 23;
                    section.data(4).dtTransOffset = 10;

                    ;% UAM_Flight_control_DW.UnitDelay10_DSTATE
                    section.data(5).logicalSrcIdx = 24;
                    section.data(5).dtTransOffset = 13;

                    ;% UAM_Flight_control_DW.UnitDelay11_DSTATE
                    section.data(6).logicalSrcIdx = 25;
                    section.data(6).dtTransOffset = 16;

                    ;% UAM_Flight_control_DW.UnitDelay12_DSTATE
                    section.data(7).logicalSrcIdx = 26;
                    section.data(7).dtTransOffset = 592;

                    ;% UAM_Flight_control_DW.UnitDelay1_9_DSTATE
                    section.data(8).logicalSrcIdx = 27;
                    section.data(8).dtTransOffset = 593;

                    ;% UAM_Flight_control_DW.UnitDelay1_8_DSTATE
                    section.data(9).logicalSrcIdx = 28;
                    section.data(9).dtTransOffset = 596;

                    ;% UAM_Flight_control_DW.UnitDelay1_6_DSTATE
                    section.data(10).logicalSrcIdx = 29;
                    section.data(10).dtTransOffset = 606;

                    ;% UAM_Flight_control_DW.UnitDelay1_5_DSTATE
                    section.data(11).logicalSrcIdx = 30;
                    section.data(11).dtTransOffset = 607;

                    ;% UAM_Flight_control_DW.UnitDelay1_4_DSTATE
                    section.data(12).logicalSrcIdx = 31;
                    section.data(12).dtTransOffset = 610;

                    ;% UAM_Flight_control_DW.UnitDelay1_3_DSTATE
                    section.data(13).logicalSrcIdx = 32;
                    section.data(13).dtTransOffset = 613;

                    ;% UAM_Flight_control_DW.UnitDelay1_2_DSTATE
                    section.data(14).logicalSrcIdx = 33;
                    section.data(14).dtTransOffset = 616;

                    ;% UAM_Flight_control_DW.UnitDelay1_1_DSTATE
                    section.data(15).logicalSrcIdx = 34;
                    section.data(15).dtTransOffset = 619;

                    ;% UAM_Flight_control_DW.UnitDelay2_DSTATE
                    section.data(16).logicalSrcIdx = 35;
                    section.data(16).dtTransOffset = 623;

                    ;% UAM_Flight_control_DW.UnitDelay1_10_DSTATE
                    section.data(17).logicalSrcIdx = 36;
                    section.data(17).dtTransOffset = 624;

                    ;% UAM_Flight_control_DW.UnitDelay_1_DSTATE
                    section.data(18).logicalSrcIdx = 37;
                    section.data(18).dtTransOffset = 625;

                    ;% UAM_Flight_control_DW.UnitDelay_2_DSTATE_g
                    section.data(19).logicalSrcIdx = 38;
                    section.data(19).dtTransOffset = 626;

                    ;% UAM_Flight_control_DW.UnitDelay_3_DSTATE_i
                    section.data(20).logicalSrcIdx = 39;
                    section.data(20).dtTransOffset = 627;

                    ;% UAM_Flight_control_DW.UnitDelay_4_DSTATE
                    section.data(21).logicalSrcIdx = 40;
                    section.data(21).dtTransOffset = 628;

                    ;% UAM_Flight_control_DW.UnitDelay_1_DSTATE_b
                    section.data(22).logicalSrcIdx = 41;
                    section.data(22).dtTransOffset = 629;

                    ;% UAM_Flight_control_DW.UnitDelay_2_DSTATE_k
                    section.data(23).logicalSrcIdx = 42;
                    section.data(23).dtTransOffset = 630;

                    ;% UAM_Flight_control_DW.UnitDelay_3_DSTATE_b
                    section.data(24).logicalSrcIdx = 43;
                    section.data(24).dtTransOffset = 631;

                    ;% UAM_Flight_control_DW.UnitDelay_4_DSTATE_f
                    section.data(25).logicalSrcIdx = 44;
                    section.data(25).dtTransOffset = 632;

                    ;% UAM_Flight_control_DW.UnitDelay1_DSTATE
                    section.data(26).logicalSrcIdx = 45;
                    section.data(26).dtTransOffset = 633;

                    ;% UAM_Flight_control_DW.UnitDelay_DSTATE
                    section.data(27).logicalSrcIdx = 46;
                    section.data(27).dtTransOffset = 634;

                    ;% UAM_Flight_control_DW.Filter_DSTATE
                    section.data(28).logicalSrcIdx = 51;
                    section.data(28).dtTransOffset = 635;

                    ;% UAM_Flight_control_DW.Integrator_DSTATE
                    section.data(29).logicalSrcIdx = 52;
                    section.data(29).dtTransOffset = 636;

                    ;% UAM_Flight_control_DW.Filter_DSTATE_l
                    section.data(30).logicalSrcIdx = 53;
                    section.data(30).dtTransOffset = 637;

                    ;% UAM_Flight_control_DW.Integrator_DSTATE_a
                    section.data(31).logicalSrcIdx = 54;
                    section.data(31).dtTransOffset = 638;

                    ;% UAM_Flight_control_DW.Integrator_DSTATE_h
                    section.data(32).logicalSrcIdx = 55;
                    section.data(32).dtTransOffset = 639;

                    ;% UAM_Flight_control_DW.Filter_DSTATE_m
                    section.data(33).logicalSrcIdx = 56;
                    section.data(33).dtTransOffset = 640;

                    ;% UAM_Flight_control_DW.Integrator_DSTATE_c
                    section.data(34).logicalSrcIdx = 57;
                    section.data(34).dtTransOffset = 641;

                    ;% UAM_Flight_control_DW.Filter_DSTATE_lr
                    section.data(35).logicalSrcIdx = 58;
                    section.data(35).dtTransOffset = 642;

                    ;% UAM_Flight_control_DW.Integrator_DSTATE_j
                    section.data(36).logicalSrcIdx = 59;
                    section.data(36).dtTransOffset = 643;

                    ;% UAM_Flight_control_DW.Filter_DSTATE_c
                    section.data(37).logicalSrcIdx = 60;
                    section.data(37).dtTransOffset = 644;

                    ;% UAM_Flight_control_DW.Integrator_DSTATE_hy
                    section.data(38).logicalSrcIdx = 61;
                    section.data(38).dtTransOffset = 645;

                    ;% UAM_Flight_control_DW.Filter_DSTATE_lq
                    section.data(39).logicalSrcIdx = 62;
                    section.data(39).dtTransOffset = 646;

                    ;% UAM_Flight_control_DW.Integrator_DSTATE_o
                    section.data(40).logicalSrcIdx = 63;
                    section.data(40).dtTransOffset = 647;

                    ;% UAM_Flight_control_DW.Filter_DSTATE_n
                    section.data(41).logicalSrcIdx = 64;
                    section.data(41).dtTransOffset = 648;

                    ;% UAM_Flight_control_DW.UnitDelay_DSTATE_f
                    section.data(42).logicalSrcIdx = 65;
                    section.data(42).dtTransOffset = 649;

                    ;% UAM_Flight_control_DW.Filter_DSTATE_a
                    section.data(43).logicalSrcIdx = 66;
                    section.data(43).dtTransOffset = 650;

                    ;% UAM_Flight_control_DW.Integrator_DSTATE_on
                    section.data(44).logicalSrcIdx = 67;
                    section.data(44).dtTransOffset = 651;

                    ;% UAM_Flight_control_DW.Integrator_DSTATE_d
                    section.data(45).logicalSrcIdx = 68;
                    section.data(45).dtTransOffset = 652;

                    ;% UAM_Flight_control_DW.Filter_DSTATE_p
                    section.data(46).logicalSrcIdx = 69;
                    section.data(46).dtTransOffset = 653;

                    ;% UAM_Flight_control_DW.Filter_DSTATE_mx
                    section.data(47).logicalSrcIdx = 70;
                    section.data(47).dtTransOffset = 654;

                    ;% UAM_Flight_control_DW.Integrator_DSTATE_cj
                    section.data(48).logicalSrcIdx = 71;
                    section.data(48).dtTransOffset = 655;

                    ;% UAM_Flight_control_DW.UnitDelay1_DSTATE_l
                    section.data(49).logicalSrcIdx = 72;
                    section.data(49).dtTransOffset = 656;

                    ;% UAM_Flight_control_DW.Integrator_DSTATE_n
                    section.data(50).logicalSrcIdx = 73;
                    section.data(50).dtTransOffset = 657;

                    ;% UAM_Flight_control_DW.Filter_DSTATE_c5
                    section.data(51).logicalSrcIdx = 74;
                    section.data(51).dtTransOffset = 658;

                    ;% UAM_Flight_control_DW.Integrator_DSTATE_jv
                    section.data(52).logicalSrcIdx = 75;
                    section.data(52).dtTransOffset = 659;

                    ;% UAM_Flight_control_DW.Filter_DSTATE_nj
                    section.data(53).logicalSrcIdx = 76;
                    section.data(53).dtTransOffset = 660;

                    ;% UAM_Flight_control_DW.Integrator_DSTATE_m
                    section.data(54).logicalSrcIdx = 77;
                    section.data(54).dtTransOffset = 661;

                    ;% UAM_Flight_control_DW.UnitDelay_DSTATE_i
                    section.data(55).logicalSrcIdx = 78;
                    section.data(55).dtTransOffset = 662;

                    ;% UAM_Flight_control_DW.UnitDelay1_DSTATE_p
                    section.data(56).logicalSrcIdx = 79;
                    section.data(56).dtTransOffset = 663;

                    ;% UAM_Flight_control_DW.Integrator_DSTATE_f
                    section.data(57).logicalSrcIdx = 80;
                    section.data(57).dtTransOffset = 664;

                    ;% UAM_Flight_control_DW.Filter_DSTATE_mr
                    section.data(58).logicalSrcIdx = 81;
                    section.data(58).dtTransOffset = 665;

                    ;% UAM_Flight_control_DW.Integrator_DSTATE_j3
                    section.data(59).logicalSrcIdx = 82;
                    section.data(59).dtTransOffset = 666;

                    ;% UAM_Flight_control_DW.Filter_DSTATE_a4
                    section.data(60).logicalSrcIdx = 83;
                    section.data(60).dtTransOffset = 667;

                    ;% UAM_Flight_control_DW.UnitDelay_DSTATE_e
                    section.data(61).logicalSrcIdx = 84;
                    section.data(61).dtTransOffset = 668;

                    ;% UAM_Flight_control_DW.Integrator_DSTATE_a2
                    section.data(62).logicalSrcIdx = 85;
                    section.data(62).dtTransOffset = 669;

                    ;% UAM_Flight_control_DW.Filter_DSTATE_f
                    section.data(63).logicalSrcIdx = 86;
                    section.data(63).dtTransOffset = 670;

                    ;% UAM_Flight_control_DW.UnitDelay_DSTATE_g
                    section.data(64).logicalSrcIdx = 87;
                    section.data(64).dtTransOffset = 671;

                    ;% UAM_Flight_control_DW.Integrator_DSTATE_p
                    section.data(65).logicalSrcIdx = 88;
                    section.data(65).dtTransOffset = 672;

                    ;% UAM_Flight_control_DW.Filter_DSTATE_px
                    section.data(66).logicalSrcIdx = 89;
                    section.data(66).dtTransOffset = 673;

                    ;% UAM_Flight_control_DW.RateTransition1_1_Buffer
                    section.data(67).logicalSrcIdx = 90;
                    section.data(67).dtTransOffset = 674;

                    ;% UAM_Flight_control_DW.RateTransition1_17_Buffer
                    section.data(68).logicalSrcIdx = 91;
                    section.data(68).dtTransOffset = 675;

                    ;% UAM_Flight_control_DW.lat0
                    section.data(69).logicalSrcIdx = 92;
                    section.data(69).dtTransOffset = 678;

                    ;% UAM_Flight_control_DW.lon0
                    section.data(70).logicalSrcIdx = 93;
                    section.data(70).dtTransOffset = 679;

                    ;% UAM_Flight_control_DW.alt0
                    section.data(71).logicalSrcIdx = 94;
                    section.data(71).dtTransOffset = 680;

                    ;% UAM_Flight_control_DW.y
                    section.data(72).logicalSrcIdx = 95;
                    section.data(72).dtTransOffset = 681;

                    ;% UAM_Flight_control_DW.p0_Pa
                    section.data(73).logicalSrcIdx = 96;
                    section.data(73).dtTransOffset = 682;

                    ;% UAM_Flight_control_DW.homeLLA
                    section.data(74).logicalSrcIdx = 97;
                    section.data(74).dtTransOffset = 683;

                    ;% UAM_Flight_control_DW.prevArming
                    section.data(75).logicalSrcIdx = 98;
                    section.data(75).dtTransOffset = 686;

                    ;% UAM_Flight_control_DW.ramp_progress
                    section.data(76).logicalSrcIdx = 101;
                    section.data(76).dtTransOffset = 687;

                    ;% UAM_Flight_control_DW.spoolup_timer
                    section.data(77).logicalSrcIdx = 102;
                    section.data(77).dtTransOffset = 688;

                    ;% UAM_Flight_control_DW.sf_internal_action_state_placeh
                    section.data(78).logicalSrcIdx = 103;
                    section.data(78).dtTransOffset = 689;

                    ;% UAM_Flight_control_DW.sf_internal_action_state_plac_f
                    section.data(79).logicalSrcIdx = 104;
                    section.data(79).dtTransOffset = 690;

                    ;% UAM_Flight_control_DW.sf_internal_action_state_plac_m
                    section.data(80).logicalSrcIdx = 105;
                    section.data(80).dtTransOffset = 691;

                    ;% UAM_Flight_control_DW.sf_internal_action_state_plac_e
                    section.data(81).logicalSrcIdx = 106;
                    section.data(81).dtTransOffset = 692;

                    ;% UAM_Flight_control_DW.sf_internal_action_state_pla_ed
                    section.data(82).logicalSrcIdx = 107;
                    section.data(82).dtTransOffset = 693;

                    ;% UAM_Flight_control_DW.sf_internal_action_state_pla_fu
                    section.data(83).logicalSrcIdx = 108;
                    section.data(83).dtTransOffset = 694;

                    ;% UAM_Flight_control_DW.sf_internal_action_state_plac_h
                    section.data(84).logicalSrcIdx = 109;
                    section.data(84).dtTransOffset = 695;

                    ;% UAM_Flight_control_DW.sf_internal_action_state_plac_p
                    section.data(85).logicalSrcIdx = 110;
                    section.data(85).dtTransOffset = 696;

                    ;% UAM_Flight_control_DW.sf_internal_action_state_plac_j
                    section.data(86).logicalSrcIdx = 111;
                    section.data(86).dtTransOffset = 697;

                    ;% UAM_Flight_control_DW.sf_internal_action_state_plac_d
                    section.data(87).logicalSrcIdx = 112;
                    section.data(87).dtTransOffset = 698;

                    ;% UAM_Flight_control_DW.timer
                    section.data(88).logicalSrcIdx = 113;
                    section.data(88).dtTransOffset = 699;

                    ;% UAM_Flight_control_DW.outWPS
                    section.data(89).logicalSrcIdx = 114;
                    section.data(89).dtTransOffset = 700;

                    ;% UAM_Flight_control_DW.hold_n
                    section.data(90).logicalSrcIdx = 115;
                    section.data(90).dtTransOffset = 708;

                    ;% UAM_Flight_control_DW.hold_e
                    section.data(91).logicalSrcIdx = 116;
                    section.data(91).dtTransOffset = 709;

                    ;% UAM_Flight_control_DW.alt_cmd
                    section.data(92).logicalSrcIdx = 117;
                    section.data(92).dtTransOffset = 710;

                    ;% UAM_Flight_control_DW.outWPS_o
                    section.data(93).logicalSrcIdx = 118;
                    section.data(93).dtTransOffset = 711;

                    ;% UAM_Flight_control_DW.outWPS_a
                    section.data(94).logicalSrcIdx = 119;
                    section.data(94).dtTransOffset = 719;

                    ;% UAM_Flight_control_DW.PrevY
                    section.data(95).logicalSrcIdx = 120;
                    section.data(95).dtTransOffset = 727;

                    ;% UAM_Flight_control_DW.PrevY_i
                    section.data(96).logicalSrcIdx = 121;
                    section.data(96).dtTransOffset = 728;

                    ;% UAM_Flight_control_DW.last_yaw_sp
                    section.data(97).logicalSrcIdx = 122;
                    section.data(97).dtTransOffset = 729;

            nTotData = nTotData + section.nData;
            dworkMap.sections(13) = section;
            clear section

            section.nData     = 13;
            section.data(13)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.WAYPOINT_execBlock
                    section.data(1).logicalSrcIdx = 123;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_DW.ORBIT_execBlock
                    section.data(2).logicalSrcIdx = 124;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_DW.Takeoff_execBlock
                    section.data(3).logicalSrcIdx = 125;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_DW.WP_execBlock
                    section.data(4).logicalSrcIdx = 126;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_DW.Orbit_execBlock
                    section.data(5).logicalSrcIdx = 127;
                    section.data(5).dtTransOffset = 4;

                    ;% UAM_Flight_control_DW.BackTransition_execBlock
                    section.data(6).logicalSrcIdx = 128;
                    section.data(6).dtTransOffset = 5;

                    ;% UAM_Flight_control_DW.ForwardTransition_execBlock
                    section.data(7).logicalSrcIdx = 129;
                    section.data(7).dtTransOffset = 6;

                    ;% UAM_Flight_control_DW.AbortLoiter_execBlock
                    section.data(8).logicalSrcIdx = 130;
                    section.data(8).dtTransOffset = 7;

                    ;% UAM_Flight_control_DW.Descend_execBlock
                    section.data(9).logicalSrcIdx = 131;
                    section.data(9).dtTransOffset = 8;

                    ;% UAM_Flight_control_DW.ToLand_execBlock
                    section.data(10).logicalSrcIdx = 132;
                    section.data(10).dtTransOffset = 9;

                    ;% UAM_Flight_control_DW.Scope_PWORK.LoggedData
                    section.data(11).logicalSrcIdx = 133;
                    section.data(11).dtTransOffset = 10;

                    ;% UAM_Flight_control_DW.Scope_PWORK_l.LoggedData
                    section.data(12).logicalSrcIdx = 134;
                    section.data(12).dtTransOffset = 11;

                    ;% UAM_Flight_control_DW.Scope_PWORK_i.LoggedData
                    section.data(13).logicalSrcIdx = 135;
                    section.data(13).dtTransOffset = 12;

            nTotData = nTotData + section.nData;
            dworkMap.sections(14) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.UnitDelay_8_DSTATE
                    section.data(1).logicalSrcIdx = 136;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_DW.UnitDelay_8_DSTATE_d
                    section.data(2).logicalSrcIdx = 137;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_DW.UnitDelay_8_DSTATE_p
                    section.data(3).logicalSrcIdx = 138;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(15) = section;
            clear section

            section.nData     = 11;
            section.data(11)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.is_c1_UAM_Flight_control
                    section.data(1).logicalSrcIdx = 163;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_DW.is_c11_UAM_Flight_control
                    section.data(2).logicalSrcIdx = 164;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_DW.is_STATE_MACHINE
                    section.data(3).logicalSrcIdx = 165;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_DW.is_c3_UAM_Flight_control
                    section.data(4).logicalSrcIdx = 166;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_DW.is_GuidanceLogic
                    section.data(5).logicalSrcIdx = 167;
                    section.data(5).dtTransOffset = 4;

                    ;% UAM_Flight_control_DW.is_FIXED_WING_ENTRY
                    section.data(6).logicalSrcIdx = 168;
                    section.data(6).dtTransOffset = 5;

                    ;% UAM_Flight_control_DW.is_FIXED_WING_ORBIT
                    section.data(7).logicalSrcIdx = 169;
                    section.data(7).dtTransOffset = 6;

                    ;% UAM_Flight_control_DW.is_FIXED_WING_WAYPOINT
                    section.data(8).logicalSrcIdx = 170;
                    section.data(8).dtTransOffset = 7;

                    ;% UAM_Flight_control_DW.is_Land
                    section.data(9).logicalSrcIdx = 171;
                    section.data(9).dtTransOffset = 8;

                    ;% UAM_Flight_control_DW.is_c12_UAM_Flight_control
                    section.data(10).logicalSrcIdx = 172;
                    section.data(10).dtTransOffset = 9;

                    ;% UAM_Flight_control_DW.is_STATE_MACHINE_g
                    section.data(11).logicalSrcIdx = 173;
                    section.data(11).dtTransOffset = 10;

            nTotData = nTotData + section.nData;
            dworkMap.sections(16) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.temporalCounter_i1
                    section.data(1).logicalSrcIdx = 176;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(17) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.UnitDelay_1_DSTATE_e
                    section.data(1).logicalSrcIdx = 177;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_DW.UnitDelay_9_DSTATE
                    section.data(2).logicalSrcIdx = 178;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_DW.UnitDelay_9_DSTATE_e
                    section.data(3).logicalSrcIdx = 179;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_DW.UnitDelay_9_DSTATE_h
                    section.data(4).logicalSrcIdx = 180;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_DW.UnitDelay_DSTATE_d
                    section.data(5).logicalSrcIdx = 181;
                    section.data(5).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            dworkMap.sections(18) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.DelayInput1_DSTATE
                    section.data(1).logicalSrcIdx = 182;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_DW.DelayInput1_DSTATE_e
                    section.data(2).logicalSrcIdx = 183;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_DW.DelayInput1_DSTATE_b
                    section.data(3).logicalSrcIdx = 184;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_DW.DelayInput1_DSTATE_f
                    section.data(4).logicalSrcIdx = 185;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            dworkMap.sections(19) = section;
            clear section

            section.nData     = 85;
            section.data(85)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.DiscreteTimeIntegrator_DSTATE
                    section.data(1).logicalSrcIdx = 186;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_DW.DiscreteTimeIntegrator_DSTATE_i
                    section.data(2).logicalSrcIdx = 187;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_DW.SwitchCase_ActiveSubsystem_m
                    section.data(3).logicalSrcIdx = 189;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_DW.Auto_SubsysRanBC
                    section.data(4).logicalSrcIdx = 190;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_DW.Emergency_SubsysRanBC
                    section.data(5).logicalSrcIdx = 191;
                    section.data(5).dtTransOffset = 4;

                    ;% UAM_Flight_control_DW.Auto_SubsysRanBC_j
                    section.data(6).logicalSrcIdx = 192;
                    section.data(6).dtTransOffset = 5;

                    ;% UAM_Flight_control_DW.TmpIfAtGuidanceLogicFIXED_WING_
                    section.data(7).logicalSrcIdx = 193;
                    section.data(7).dtTransOffset = 6;

                    ;% UAM_Flight_control_DW.TmpIfAtGuidanceLogicWPInport4_A
                    section.data(8).logicalSrcIdx = 194;
                    section.data(8).dtTransOffset = 7;

                    ;% UAM_Flight_control_DW.TmpIfAtGuidanceLogicLandToLandI
                    section.data(9).logicalSrcIdx = 195;
                    section.data(9).dtTransOffset = 8;

                    ;% UAM_Flight_control_DW.GuidanceLogicWP_SubsysRanBC
                    section.data(10).logicalSrcIdx = 196;
                    section.data(10).dtTransOffset = 9;

                    ;% UAM_Flight_control_DW.TriggeredSubsystem_SubsysRanBC
                    section.data(11).logicalSrcIdx = 197;
                    section.data(11).dtTransOffset = 10;

                    ;% UAM_Flight_control_DW.GuidanceLogicTakeoff_SubsysRanB
                    section.data(12).logicalSrcIdx = 198;
                    section.data(12).dtTransOffset = 11;

                    ;% UAM_Flight_control_DW.GuidanceLogicOrbit_SubsysRanBC
                    section.data(13).logicalSrcIdx = 199;
                    section.data(13).dtTransOffset = 12;

                    ;% UAM_Flight_control_DW.GuidanceLogicLandToLand_SubsysR
                    section.data(14).logicalSrcIdx = 200;
                    section.data(14).dtTransOffset = 13;

                    ;% UAM_Flight_control_DW.GuidanceLogicLandDescend_Subsys
                    section.data(15).logicalSrcIdx = 201;
                    section.data(15).dtTransOffset = 14;

                    ;% UAM_Flight_control_DW.GuidanceLogicLandAbortLoiter_Su
                    section.data(16).logicalSrcIdx = 202;
                    section.data(16).dtTransOffset = 15;

                    ;% UAM_Flight_control_DW.GuidanceLogicForwardTransition_
                    section.data(17).logicalSrcIdx = 203;
                    section.data(17).dtTransOffset = 16;

                    ;% UAM_Flight_control_DW.GuidanceLogicFIXED_WING_WAYPOIN
                    section.data(18).logicalSrcIdx = 204;
                    section.data(18).dtTransOffset = 17;

                    ;% UAM_Flight_control_DW.GuidanceLogicFIXED_WING_ORBITOR
                    section.data(19).logicalSrcIdx = 205;
                    section.data(19).dtTransOffset = 18;

                    ;% UAM_Flight_control_DW.GuidanceLogicBackTransition_Sub
                    section.data(20).logicalSrcIdx = 206;
                    section.data(20).dtTransOffset = 19;

                    ;% UAM_Flight_control_DW.Manual_SubsysRanBC
                    section.data(21).logicalSrcIdx = 207;
                    section.data(21).dtTransOffset = 20;

                    ;% UAM_Flight_control_DW.Emergency_SubsysRanBC_o
                    section.data(22).logicalSrcIdx = 208;
                    section.data(22).dtTransOffset = 21;

                    ;% UAM_Flight_control_DW.multicopterController_SubsysRan
                    section.data(23).logicalSrcIdx = 209;
                    section.data(23).dtTransOffset = 22;

                    ;% UAM_Flight_control_DW.Scheduler_SubsysRanBC
                    section.data(24).logicalSrcIdx = 210;
                    section.data(24).dtTransOffset = 23;

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem3_Subs
                    section.data(25).logicalSrcIdx = 211;
                    section.data(25).dtTransOffset = 24;

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem1_Subs
                    section.data(26).logicalSrcIdx = 212;
                    section.data(26).dtTransOffset = 25;

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem_Subsy
                    section.data(27).logicalSrcIdx = 213;
                    section.data(27).dtTransOffset = 26;

                    ;% UAM_Flight_control_DW.FixedWingController_SubsysRanBC
                    section.data(28).logicalSrcIdx = 214;
                    section.data(28).dtTransOffset = 27;

                    ;% UAM_Flight_control_DW.AttitudeController_SubsysRanBC
                    section.data(29).logicalSrcIdx = 215;
                    section.data(29).dtTransOffset = 28;

                    ;% UAM_Flight_control_DW.PitchRollController_SubsysRanBC
                    section.data(30).logicalSrcIdx = 216;
                    section.data(30).dtTransOffset = 29;

                    ;% UAM_Flight_control_DW.Auto1_SubsysRanBC
                    section.data(31).logicalSrcIdx = 217;
                    section.data(31).dtTransOffset = 30;

                    ;% UAM_Flight_control_DW.Scheduler_SubsysRanBC_p
                    section.data(32).logicalSrcIdx = 218;
                    section.data(32).dtTransOffset = 31;

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem3_Su_m
                    section.data(33).logicalSrcIdx = 219;
                    section.data(33).dtTransOffset = 32;

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem1_Su_n
                    section.data(34).logicalSrcIdx = 220;
                    section.data(34).dtTransOffset = 33;

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem_Sub_g
                    section.data(35).logicalSrcIdx = 221;
                    section.data(35).dtTransOffset = 34;

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem2_Subs
                    section.data(36).logicalSrcIdx = 222;
                    section.data(36).dtTransOffset = 35;

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem1_Su_b
                    section.data(37).logicalSrcIdx = 223;
                    section.data(37).dtTransOffset = 36;

                    ;% UAM_Flight_control_DW.MulticopterController_SubsysRan
                    section.data(38).logicalSrcIdx = 224;
                    section.data(38).dtTransOffset = 37;

                    ;% UAM_Flight_control_DW.Integrator_PrevResetState
                    section.data(39).logicalSrcIdx = 225;
                    section.data(39).dtTransOffset = 38;

                    ;% UAM_Flight_control_DW.Integrator_PrevResetState_e
                    section.data(40).logicalSrcIdx = 226;
                    section.data(40).dtTransOffset = 39;

                    ;% UAM_Flight_control_DW.Filter_PrevResetState
                    section.data(41).logicalSrcIdx = 227;
                    section.data(41).dtTransOffset = 40;

                    ;% UAM_Flight_control_DW.Integrator_PrevResetState_f
                    section.data(42).logicalSrcIdx = 228;
                    section.data(42).dtTransOffset = 41;

                    ;% UAM_Flight_control_DW.Filter_PrevResetState_a
                    section.data(43).logicalSrcIdx = 229;
                    section.data(43).dtTransOffset = 42;

                    ;% UAM_Flight_control_DW.transitioncontroller_SubsysRanB
                    section.data(44).logicalSrcIdx = 230;
                    section.data(44).dtTransOffset = 43;

                    ;% UAM_Flight_control_DW.HorizontalPositionControl_Subsy
                    section.data(45).logicalSrcIdx = 231;
                    section.data(45).dtTransOffset = 44;

                    ;% UAM_Flight_control_DW.XYController_SubsysRanBC
                    section.data(46).logicalSrcIdx = 232;
                    section.data(46).dtTransOffset = 45;

                    ;% UAM_Flight_control_DW.Integrator_PrevResetState_l
                    section.data(47).logicalSrcIdx = 233;
                    section.data(47).dtTransOffset = 46;

                    ;% UAM_Flight_control_DW.Filter_PrevResetState_o
                    section.data(48).logicalSrcIdx = 234;
                    section.data(48).dtTransOffset = 47;

                    ;% UAM_Flight_control_DW.Integrator_PrevResetState_n
                    section.data(49).logicalSrcIdx = 235;
                    section.data(49).dtTransOffset = 48;

                    ;% UAM_Flight_control_DW.Filter_PrevResetState_p
                    section.data(50).logicalSrcIdx = 236;
                    section.data(50).dtTransOffset = 49;

                    ;% UAM_Flight_control_DW.AltitudeControl_SubsysRanBC
                    section.data(51).logicalSrcIdx = 237;
                    section.data(51).dtTransOffset = 50;

                    ;% UAM_Flight_control_DW.Integrator_PrevResetState_p
                    section.data(52).logicalSrcIdx = 238;
                    section.data(52).dtTransOffset = 51;

                    ;% UAM_Flight_control_DW.Filter_PrevResetState_e
                    section.data(53).logicalSrcIdx = 239;
                    section.data(53).dtTransOffset = 52;

                    ;% UAM_Flight_control_DW.TriggeredSubsystem_SubsysRanB_c
                    section.data(54).logicalSrcIdx = 240;
                    section.data(54).dtTransOffset = 53;

                    ;% UAM_Flight_control_DW.FixedWingController_SubsysRan_d
                    section.data(55).logicalSrcIdx = 241;
                    section.data(55).dtTransOffset = 54;

                    ;% UAM_Flight_control_DW.RollSPfromPathManager_SubsysRan
                    section.data(56).logicalSrcIdx = 242;
                    section.data(56).dtTransOffset = 55;

                    ;% UAM_Flight_control_DW.PitchAirspeedSPfromController_S
                    section.data(57).logicalSrcIdx = 243;
                    section.data(57).dtTransOffset = 56;

                    ;% UAM_Flight_control_DW.LateralGuidanceLogic_SubsysRanB
                    section.data(58).logicalSrcIdx = 244;
                    section.data(58).dtTransOffset = 57;

                    ;% UAM_Flight_control_DW.AttitudeController_SubsysRanB_m
                    section.data(59).logicalSrcIdx = 245;
                    section.data(59).dtTransOffset = 58;

                    ;% UAM_Flight_control_DW.RudderHeadingController_SubsysR
                    section.data(60).logicalSrcIdx = 246;
                    section.data(60).dtTransOffset = 59;

                    ;% UAM_Flight_control_DW.PitchRollController_SubsysRan_l
                    section.data(61).logicalSrcIdx = 247;
                    section.data(61).dtTransOffset = 60;

                    ;% UAM_Flight_control_DW.AirspeedAltitudeController_Subs
                    section.data(62).logicalSrcIdx = 248;
                    section.data(62).dtTransOffset = 61;

                    ;% UAM_Flight_control_DW.ClimbRateSPfromGuidance_SubsysR
                    section.data(63).logicalSrcIdx = 249;
                    section.data(63).dtTransOffset = 62;

                    ;% UAM_Flight_control_DW.Altitudecontroller_SubsysRanBC
                    section.data(64).logicalSrcIdx = 250;
                    section.data(64).dtTransOffset = 63;

                    ;% UAM_Flight_control_DW.AERfromPathManager_SubsysRanBC
                    section.data(65).logicalSrcIdx = 251;
                    section.data(65).dtTransOffset = 64;

                    ;% UAM_Flight_control_DW.Manual_SubsysRanBC_o
                    section.data(66).logicalSrcIdx = 252;
                    section.data(66).dtTransOffset = 65;

                    ;% UAM_Flight_control_DW.multicopterController_SubsysR_l
                    section.data(67).logicalSrcIdx = 253;
                    section.data(67).dtTransOffset = 66;

                    ;% UAM_Flight_control_DW.Subsystem_SubsysRanBC
                    section.data(68).logicalSrcIdx = 254;
                    section.data(68).dtTransOffset = 67;

                    ;% UAM_Flight_control_DW.HorizontalPositionControl1_Subs
                    section.data(69).logicalSrcIdx = 255;
                    section.data(69).dtTransOffset = 68;

                    ;% UAM_Flight_control_DW.Integrator_PrevResetState_i
                    section.data(70).logicalSrcIdx = 256;
                    section.data(70).dtTransOffset = 69;

                    ;% UAM_Flight_control_DW.Filter_PrevResetState_l
                    section.data(71).logicalSrcIdx = 257;
                    section.data(71).dtTransOffset = 70;

                    ;% UAM_Flight_control_DW.Integrator_PrevResetState_pz
                    section.data(72).logicalSrcIdx = 258;
                    section.data(72).dtTransOffset = 71;

                    ;% UAM_Flight_control_DW.Filter_PrevResetState_c
                    section.data(73).logicalSrcIdx = 259;
                    section.data(73).dtTransOffset = 72;

                    ;% UAM_Flight_control_DW.EnabledSubsystem_SubsysRanBC
                    section.data(74).logicalSrcIdx = 260;
                    section.data(74).dtTransOffset = 73;

                    ;% UAM_Flight_control_DW.AltitudeControl1_SubsysRanBC
                    section.data(75).logicalSrcIdx = 261;
                    section.data(75).dtTransOffset = 74;

                    ;% UAM_Flight_control_DW.Integrator_PrevResetState_f5
                    section.data(76).logicalSrcIdx = 262;
                    section.data(76).dtTransOffset = 75;

                    ;% UAM_Flight_control_DW.Filter_PrevResetState_m
                    section.data(77).logicalSrcIdx = 263;
                    section.data(77).dtTransOffset = 76;

                    ;% UAM_Flight_control_DW.Scheduler_SubsysRanBC_f
                    section.data(78).logicalSrcIdx = 264;
                    section.data(78).dtTransOffset = 77;

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem3_Su_p
                    section.data(79).logicalSrcIdx = 265;
                    section.data(79).dtTransOffset = 78;

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem2_Su_e
                    section.data(80).logicalSrcIdx = 266;
                    section.data(80).dtTransOffset = 79;

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem1_Su_a
                    section.data(81).logicalSrcIdx = 267;
                    section.data(81).dtTransOffset = 80;

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem_Sub_k
                    section.data(82).logicalSrcIdx = 268;
                    section.data(82).dtTransOffset = 81;

                    ;% UAM_Flight_control_DW.FixedWingController_SubsysRan_j
                    section.data(83).logicalSrcIdx = 269;
                    section.data(83).dtTransOffset = 82;

                    ;% UAM_Flight_control_DW.AttitudeController_SubsysRanB_e
                    section.data(84).logicalSrcIdx = 270;
                    section.data(84).dtTransOffset = 83;

                    ;% UAM_Flight_control_DW.PitchRollController_SubsysRan_c
                    section.data(85).logicalSrcIdx = 271;
                    section.data(85).dtTransOffset = 84;

            nTotData = nTotData + section.nData;
            dworkMap.sections(20) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.last_arm
                    section.data(1).logicalSrcIdx = 272;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_DW.is_active_c1_UAM_Flight_control
                    section.data(2).logicalSrcIdx = 273;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_DW.is_active_c11_UAM_Flight_contro
                    section.data(3).logicalSrcIdx = 274;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_DW.is_active_c3_UAM_Flight_control
                    section.data(4).logicalSrcIdx = 275;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_DW.mode_start
                    section.data(5).logicalSrcIdx = 277;
                    section.data(5).dtTransOffset = 4;

                    ;% UAM_Flight_control_DW.is_active_c12_UAM_Flight_contro
                    section.data(6).logicalSrcIdx = 278;
                    section.data(6).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            dworkMap.sections(21) = section;
            clear section

            section.nData     = 17;
            section.data(17)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.locked
                    section.data(1).logicalSrcIdx = 283;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_DW.init
                    section.data(2).logicalSrcIdx = 288;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_DW.p0_set
                    section.data(3).logicalSrcIdx = 292;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_DW.isSet
                    section.data(4).logicalSrcIdx = 298;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_DW.IC_FirstOutputTime
                    section.data(5).logicalSrcIdx = 304;
                    section.data(5).dtTransOffset = 4;

                    ;% UAM_Flight_control_DW.init_flag_not_empty
                    section.data(6).logicalSrcIdx = 319;
                    section.data(6).dtTransOffset = 5;

                    ;% UAM_Flight_control_DW.IC_FirstOutputTime_a
                    section.data(7).logicalSrcIdx = 330;
                    section.data(7).dtTransOffset = 6;

                    ;% UAM_Flight_control_DW.Scheduler_MODE
                    section.data(8).logicalSrcIdx = 336;
                    section.data(8).dtTransOffset = 7;

                    ;% UAM_Flight_control_DW.Scheduler_MODE_p
                    section.data(9).logicalSrcIdx = 337;
                    section.data(9).dtTransOffset = 8;

                    ;% UAM_Flight_control_DW.MulticopterController_MODE
                    section.data(10).logicalSrcIdx = 338;
                    section.data(10).dtTransOffset = 9;

                    ;% UAM_Flight_control_DW.HorizontalPositionControl_MODE
                    section.data(11).logicalSrcIdx = 339;
                    section.data(11).dtTransOffset = 10;

                    ;% UAM_Flight_control_DW.XYController_MODE
                    section.data(12).logicalSrcIdx = 340;
                    section.data(12).dtTransOffset = 11;

                    ;% UAM_Flight_control_DW.AltitudeControl_MODE
                    section.data(13).logicalSrcIdx = 341;
                    section.data(13).dtTransOffset = 12;

                    ;% UAM_Flight_control_DW.multicopterController_MODE
                    section.data(14).logicalSrcIdx = 342;
                    section.data(14).dtTransOffset = 13;

                    ;% UAM_Flight_control_DW.HorizontalPositionControl1_MODE
                    section.data(15).logicalSrcIdx = 343;
                    section.data(15).dtTransOffset = 14;

                    ;% UAM_Flight_control_DW.AltitudeControl1_MODE
                    section.data(16).logicalSrcIdx = 344;
                    section.data(16).dtTransOffset = 15;

                    ;% UAM_Flight_control_DW.Scheduler_MODE_pr
                    section.data(17).logicalSrcIdx = 345;
                    section.data(17).dtTransOffset = 16;

            nTotData = nTotData + section.nData;
            dworkMap.sections(22) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.Emergency_b.SwitchCaseActionSubsystem_Subsy
                    section.data(1).logicalSrcIdx = 346;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(23) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem.SwitchCaseActionSubsystem_Subsy
                    section.data(1).logicalSrcIdx = 347;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(24) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.WaypointFollower_ni.obj
                    section.data(1).logicalSrcIdx = 348;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(25) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.WaypointFollower_ni.objisempty
                    section.data(1).logicalSrcIdx = 349;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(26) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.WaypointFollower_n.obj
                    section.data(1).logicalSrcIdx = 350;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(27) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.WaypointFollower_n.objisempty
                    section.data(1).logicalSrcIdx = 351;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(28) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem2_n.SwitchCaseActionSubsystem2_Subs
                    section.data(1).logicalSrcIdx = 352;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(29) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem3_g.SwitchCaseActionSubsystem_Subsy
                    section.data(1).logicalSrcIdx = 353;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(30) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem2_c.SwitchCaseActionSubsystem2_Subs
                    section.data(1).logicalSrcIdx = 354;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(31) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem1_m.SwitchCaseActionSubsystem1_Subs
                    section.data(1).logicalSrcIdx = 355;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(32) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem_e.SwitchCaseActionSubsystem_Subsy
                    section.data(1).logicalSrcIdx = 356;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(33) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.sf_MATLABFunction_j.sfEvent
                    section.data(1).logicalSrcIdx = 357;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(34) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.sf_MATLABFunction_j.doneDoubleBufferReInit
                    section.data(1).logicalSrcIdx = 358;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(35) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.sf_MATLABFunction_er.sfEvent
                    section.data(1).logicalSrcIdx = 359;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(36) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.sf_MATLABFunction_er.doneDoubleBufferReInit
                    section.data(1).logicalSrcIdx = 360;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(37) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem2_m.SwitchCaseActionSubsystem2_Subs
                    section.data(1).logicalSrcIdx = 361;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(38) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem3_e.SwitchCaseActionSubsystem_Subsy
                    section.data(1).logicalSrcIdx = 362;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(39) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem_g.SwitchCaseActionSubsystem_Subsy
                    section.data(1).logicalSrcIdx = 363;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(40) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.sf_MATLABFunction_ij.sfEvent
                    section.data(1).logicalSrcIdx = 364;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(41) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.sf_MATLABFunction_ij.doneDoubleBufferReInit
                    section.data(1).logicalSrcIdx = 365;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(42) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.sf_MATLABFunction_ac.hover_thrust
                    section.data(1).logicalSrcIdx = 366;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(43) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.sf_MATLABFunction_ac.sfEvent
                    section.data(1).logicalSrcIdx = 367;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(44) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.sf_MATLABFunction_ac.doneDoubleBufferReInit
                    section.data(1).logicalSrcIdx = 368;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_DW.sf_MATLABFunction_ac.hover_thrust_not_empty
                    section.data(2).logicalSrcIdx = 369;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(45) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.sf_MATLABFunction_g.sfEvent
                    section.data(1).logicalSrcIdx = 370;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(46) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.sf_MATLABFunction_g.doneDoubleBufferReInit
                    section.data(1).logicalSrcIdx = 371;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(47) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.sf_MATLABFunction_l.sfEvent
                    section.data(1).logicalSrcIdx = 372;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(48) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.sf_MATLABFunction_l.doneDoubleBufferReInit
                    section.data(1).logicalSrcIdx = 373;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(49) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.sf_MATLABFunction1.sfEvent
                    section.data(1).logicalSrcIdx = 374;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(50) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.sf_MATLABFunction1.doneDoubleBufferReInit
                    section.data(1).logicalSrcIdx = 375;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(51) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.sf_MATLABFunction_b.sfEvent
                    section.data(1).logicalSrcIdx = 376;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(52) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.sf_MATLABFunction_b.doneDoubleBufferReInit
                    section.data(1).logicalSrcIdx = 377;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(53) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.sf_MATLABFunction_i.sfEvent
                    section.data(1).logicalSrcIdx = 378;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(54) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.sf_MATLABFunction_i.doneDoubleBufferReInit
                    section.data(1).logicalSrcIdx = 379;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(55) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.sf_MATLABFunction_mi.hover_thrust
                    section.data(1).logicalSrcIdx = 380;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(56) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.sf_MATLABFunction_mi.sfEvent
                    section.data(1).logicalSrcIdx = 381;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(57) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.sf_MATLABFunction_mi.doneDoubleBufferReInit
                    section.data(1).logicalSrcIdx = 382;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_DW.sf_MATLABFunction_mi.hover_thrust_not_empty
                    section.data(2).logicalSrcIdx = 383;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(58) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem3.SwitchCaseActionSubsystem_Subsy
                    section.data(1).logicalSrcIdx = 384;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(59) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem2_f.SwitchCaseActionSubsystem2_Subs
                    section.data(1).logicalSrcIdx = 385;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(60) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem1_e.SwitchCaseActionSubsystem1_Subs
                    section.data(1).logicalSrcIdx = 386;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(61) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem_kk.SwitchCaseActionSubsystem_Subsy
                    section.data(1).logicalSrcIdx = 387;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(62) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.sf_MATLABFunction_a.sfEvent
                    section.data(1).logicalSrcIdx = 388;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(63) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.sf_MATLABFunction_a.doneDoubleBufferReInit
                    section.data(1).logicalSrcIdx = 389;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(64) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.sf_MATLABFunction_c.sfEvent
                    section.data(1).logicalSrcIdx = 390;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(65) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.sf_MATLABFunction_c.doneDoubleBufferReInit
                    section.data(1).logicalSrcIdx = 391;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(66) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 26580448;
    targMap.checksum1 = 312422411;
    targMap.checksum2 = 3720716136;
    targMap.checksum3 = 2813293141;

