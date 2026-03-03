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

            section.nData     = 108;
            section.data(108)  = dumData; %prealloc

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

                    ;% UAM_Flight_control_P.PitchAngleController_InitialC_g
                    section.data(8).logicalSrcIdx = 17;
                    section.data(8).dtTransOffset = 7;

                    ;% UAM_Flight_control_P.AirspeedController_InitialCon_o
                    section.data(9).logicalSrcIdx = 18;
                    section.data(9).dtTransOffset = 8;

                    ;% UAM_Flight_control_P.Lateralpositioncontroller_Initi
                    section.data(10).logicalSrcIdx = 19;
                    section.data(10).dtTransOffset = 9;

                    ;% UAM_Flight_control_P.Lateralvelocitycontroller_Ini_l
                    section.data(11).logicalSrcIdx = 20;
                    section.data(11).dtTransOffset = 10;

                    ;% UAM_Flight_control_P.Forwardpositioncontroller_Initi
                    section.data(12).logicalSrcIdx = 21;
                    section.data(12).dtTransOffset = 11;

                    ;% UAM_Flight_control_P.Forwardvelocitycontroller_Ini_e
                    section.data(13).logicalSrcIdx = 22;
                    section.data(13).dtTransOffset = 12;

                    ;% UAM_Flight_control_P.Altitudecontroller_InitialCondi
                    section.data(14).logicalSrcIdx = 23;
                    section.data(14).dtTransOffset = 13;

                    ;% UAM_Flight_control_P.Altituderatecontroller_Initia_i
                    section.data(15).logicalSrcIdx = 24;
                    section.data(15).dtTransOffset = 14;

                    ;% UAM_Flight_control_P.PitchController_InitialConditio
                    section.data(16).logicalSrcIdx = 25;
                    section.data(16).dtTransOffset = 15;

                    ;% UAM_Flight_control_P.PitchRateController_InitialCond
                    section.data(17).logicalSrcIdx = 26;
                    section.data(17).dtTransOffset = 16;

                    ;% UAM_Flight_control_P.RollController_InitialCondition
                    section.data(18).logicalSrcIdx = 27;
                    section.data(18).dtTransOffset = 17;

                    ;% UAM_Flight_control_P.RollRateController_InitialCondi
                    section.data(19).logicalSrcIdx = 28;
                    section.data(19).dtTransOffset = 18;

                    ;% UAM_Flight_control_P.YawController_InitialConditionF
                    section.data(20).logicalSrcIdx = 29;
                    section.data(20).dtTransOffset = 19;

                    ;% UAM_Flight_control_P.Yawratecontroller_InitialCondit
                    section.data(21).logicalSrcIdx = 30;
                    section.data(21).dtTransOffset = 20;

                    ;% UAM_Flight_control_P.PitchAngleController_InitialC_p
                    section.data(22).logicalSrcIdx = 31;
                    section.data(22).dtTransOffset = 21;

                    ;% UAM_Flight_control_P.Yawratecontroller_InitialCond_b
                    section.data(23).logicalSrcIdx = 32;
                    section.data(23).dtTransOffset = 22;

                    ;% UAM_Flight_control_P.PitchAngleController_InitialC_d
                    section.data(24).logicalSrcIdx = 33;
                    section.data(24).dtTransOffset = 23;

                    ;% UAM_Flight_control_P.Altituderatecontroller_Initia_j
                    section.data(25).logicalSrcIdx = 34;
                    section.data(25).dtTransOffset = 24;

                    ;% UAM_Flight_control_P.Lateralvelocitycontroller_Ini_k
                    section.data(26).logicalSrcIdx = 35;
                    section.data(26).dtTransOffset = 25;

                    ;% UAM_Flight_control_P.Forwardvelocitycontroller_Ini_i
                    section.data(27).logicalSrcIdx = 36;
                    section.data(27).dtTransOffset = 26;

                    ;% UAM_Flight_control_P.Yawratecontroller_InitialCond_c
                    section.data(28).logicalSrcIdx = 37;
                    section.data(28).dtTransOffset = 27;

                    ;% UAM_Flight_control_P.Pitchratecontroller_InitialCo_i
                    section.data(29).logicalSrcIdx = 38;
                    section.data(29).dtTransOffset = 28;

                    ;% UAM_Flight_control_P.Rollratecontroller_InitialCon_e
                    section.data(30).logicalSrcIdx = 39;
                    section.data(30).dtTransOffset = 29;

                    ;% UAM_Flight_control_P.AirspeedController_InitialCon_l
                    section.data(31).logicalSrcIdx = 40;
                    section.data(31).dtTransOffset = 30;

                    ;% UAM_Flight_control_P.PitchAngleController_InitialC_n
                    section.data(32).logicalSrcIdx = 41;
                    section.data(32).dtTransOffset = 31;

                    ;% UAM_Flight_control_P.AirspeedController_InitialCo_ov
                    section.data(33).logicalSrcIdx = 42;
                    section.data(33).dtTransOffset = 32;

                    ;% UAM_Flight_control_P.Lateralpositioncontroller_Ini_o
                    section.data(34).logicalSrcIdx = 43;
                    section.data(34).dtTransOffset = 33;

                    ;% UAM_Flight_control_P.Lateralvelocitycontroller_Ini_p
                    section.data(35).logicalSrcIdx = 44;
                    section.data(35).dtTransOffset = 34;

                    ;% UAM_Flight_control_P.Forwardpositioncontroller_Ini_a
                    section.data(36).logicalSrcIdx = 45;
                    section.data(36).dtTransOffset = 35;

                    ;% UAM_Flight_control_P.Forwardvelocitycontroller_Ini_o
                    section.data(37).logicalSrcIdx = 46;
                    section.data(37).dtTransOffset = 36;

                    ;% UAM_Flight_control_P.Altitudecontroller_InitialCon_p
                    section.data(38).logicalSrcIdx = 47;
                    section.data(38).dtTransOffset = 37;

                    ;% UAM_Flight_control_P.Altituderatecontroller_Initia_g
                    section.data(39).logicalSrcIdx = 48;
                    section.data(39).dtTransOffset = 38;

                    ;% UAM_Flight_control_P.PitchController_InitialCondit_n
                    section.data(40).logicalSrcIdx = 49;
                    section.data(40).dtTransOffset = 39;

                    ;% UAM_Flight_control_P.PitchRateController_InitialCo_j
                    section.data(41).logicalSrcIdx = 50;
                    section.data(41).dtTransOffset = 40;

                    ;% UAM_Flight_control_P.RollController_InitialConditi_l
                    section.data(42).logicalSrcIdx = 51;
                    section.data(42).dtTransOffset = 41;

                    ;% UAM_Flight_control_P.RollRateController_InitialCon_d
                    section.data(43).logicalSrcIdx = 52;
                    section.data(43).dtTransOffset = 42;

                    ;% UAM_Flight_control_P.YawController_InitialConditio_e
                    section.data(44).logicalSrcIdx = 53;
                    section.data(44).dtTransOffset = 43;

                    ;% UAM_Flight_control_P.Yawratecontroller_InitialCond_j
                    section.data(45).logicalSrcIdx = 54;
                    section.data(45).dtTransOffset = 44;

                    ;% UAM_Flight_control_P.PitchAngleController_InitialC_f
                    section.data(46).logicalSrcIdx = 55;
                    section.data(46).dtTransOffset = 45;

                    ;% UAM_Flight_control_P.Altituderatecontroller_LowerInt
                    section.data(47).logicalSrcIdx = 56;
                    section.data(47).dtTransOffset = 46;

                    ;% UAM_Flight_control_P.Lateralvelocitycontroller_Lower
                    section.data(48).logicalSrcIdx = 57;
                    section.data(48).dtTransOffset = 47;

                    ;% UAM_Flight_control_P.Forwardvelocitycontroller_Lower
                    section.data(49).logicalSrcIdx = 58;
                    section.data(49).dtTransOffset = 48;

                    ;% UAM_Flight_control_P.Yawratecontroller_LowerIntegrat
                    section.data(50).logicalSrcIdx = 59;
                    section.data(50).dtTransOffset = 49;

                    ;% UAM_Flight_control_P.Pitchratecontroller_LowerIntegr
                    section.data(51).logicalSrcIdx = 60;
                    section.data(51).dtTransOffset = 50;

                    ;% UAM_Flight_control_P.Rollratecontroller_LowerIntegra
                    section.data(52).logicalSrcIdx = 61;
                    section.data(52).dtTransOffset = 51;

                    ;% UAM_Flight_control_P.PitchAngleController_LowerSatur
                    section.data(53).logicalSrcIdx = 62;
                    section.data(53).dtTransOffset = 52;

                    ;% UAM_Flight_control_P.PitchRateController_LowerSatura
                    section.data(54).logicalSrcIdx = 63;
                    section.data(54).dtTransOffset = 53;

                    ;% UAM_Flight_control_P.RudderController_LowerSaturatio
                    section.data(55).logicalSrcIdx = 64;
                    section.data(55).dtTransOffset = 54;

                    ;% UAM_Flight_control_P.RollRateController_LowerSaturat
                    section.data(56).logicalSrcIdx = 65;
                    section.data(56).dtTransOffset = 55;

                    ;% UAM_Flight_control_P.Altituderatecontroller_LowerSat
                    section.data(57).logicalSrcIdx = 66;
                    section.data(57).dtTransOffset = 56;

                    ;% UAM_Flight_control_P.Lateralpositioncontroller_Lower
                    section.data(58).logicalSrcIdx = 67;
                    section.data(58).dtTransOffset = 57;

                    ;% UAM_Flight_control_P.Lateralvelocitycontroller_Low_p
                    section.data(59).logicalSrcIdx = 68;
                    section.data(59).dtTransOffset = 58;

                    ;% UAM_Flight_control_P.Forwardvelocitycontroller_Low_p
                    section.data(60).logicalSrcIdx = 69;
                    section.data(60).dtTransOffset = 59;

                    ;% UAM_Flight_control_P.RudderController_LowerSaturat_g
                    section.data(61).logicalSrcIdx = 70;
                    section.data(61).dtTransOffset = 60;

                    ;% UAM_Flight_control_P.PitchAngleController_LowerSat_d
                    section.data(62).logicalSrcIdx = 71;
                    section.data(62).dtTransOffset = 61;

                    ;% UAM_Flight_control_P.PitchRateController_LowerSatu_f
                    section.data(63).logicalSrcIdx = 72;
                    section.data(63).dtTransOffset = 62;

                    ;% UAM_Flight_control_P.RollRateController_LowerSatur_o
                    section.data(64).logicalSrcIdx = 73;
                    section.data(64).dtTransOffset = 63;

                    ;% UAM_Flight_control_P.PitchAngleController_LowerSat_e
                    section.data(65).logicalSrcIdx = 74;
                    section.data(65).dtTransOffset = 64;

                    ;% UAM_Flight_control_P.PitchRateController_LowerSatu_o
                    section.data(66).logicalSrcIdx = 75;
                    section.data(66).dtTransOffset = 65;

                    ;% UAM_Flight_control_P.RudderController_LowerSaturat_f
                    section.data(67).logicalSrcIdx = 76;
                    section.data(67).dtTransOffset = 66;

                    ;% UAM_Flight_control_P.RollRateController_LowerSatur_g
                    section.data(68).logicalSrcIdx = 77;
                    section.data(68).dtTransOffset = 67;

                    ;% UAM_Flight_control_P.RudderController_P
                    section.data(69).logicalSrcIdx = 78;
                    section.data(69).dtTransOffset = 68;

                    ;% UAM_Flight_control_P.Altitudecontroller_P
                    section.data(70).logicalSrcIdx = 79;
                    section.data(70).dtTransOffset = 69;

                    ;% UAM_Flight_control_P.RudderController_P_o
                    section.data(71).logicalSrcIdx = 80;
                    section.data(71).dtTransOffset = 70;

                    ;% UAM_Flight_control_P.PitchRateController_P
                    section.data(72).logicalSrcIdx = 81;
                    section.data(72).dtTransOffset = 71;

                    ;% UAM_Flight_control_P.RudderController_P_f
                    section.data(73).logicalSrcIdx = 82;
                    section.data(73).dtTransOffset = 72;

                    ;% UAM_Flight_control_P.RollController_P
                    section.data(74).logicalSrcIdx = 83;
                    section.data(74).dtTransOffset = 73;

                    ;% UAM_Flight_control_P.PitchController_P
                    section.data(75).logicalSrcIdx = 84;
                    section.data(75).dtTransOffset = 74;

                    ;% UAM_Flight_control_P.Yawratecontroller_P
                    section.data(76).logicalSrcIdx = 85;
                    section.data(76).dtTransOffset = 75;

                    ;% UAM_Flight_control_P.Altituderatecontroller_UpperInt
                    section.data(77).logicalSrcIdx = 86;
                    section.data(77).dtTransOffset = 76;

                    ;% UAM_Flight_control_P.Lateralvelocitycontroller_Upper
                    section.data(78).logicalSrcIdx = 87;
                    section.data(78).dtTransOffset = 77;

                    ;% UAM_Flight_control_P.Forwardvelocitycontroller_Upper
                    section.data(79).logicalSrcIdx = 88;
                    section.data(79).dtTransOffset = 78;

                    ;% UAM_Flight_control_P.Yawratecontroller_UpperIntegrat
                    section.data(80).logicalSrcIdx = 89;
                    section.data(80).dtTransOffset = 79;

                    ;% UAM_Flight_control_P.Pitchratecontroller_UpperIntegr
                    section.data(81).logicalSrcIdx = 90;
                    section.data(81).dtTransOffset = 80;

                    ;% UAM_Flight_control_P.Rollratecontroller_UpperIntegra
                    section.data(82).logicalSrcIdx = 91;
                    section.data(82).dtTransOffset = 81;

                    ;% UAM_Flight_control_P.PitchAngleController_UpperSatur
                    section.data(83).logicalSrcIdx = 92;
                    section.data(83).dtTransOffset = 82;

                    ;% UAM_Flight_control_P.PitchRateController_UpperSatura
                    section.data(84).logicalSrcIdx = 93;
                    section.data(84).dtTransOffset = 83;

                    ;% UAM_Flight_control_P.RudderController_UpperSaturatio
                    section.data(85).logicalSrcIdx = 94;
                    section.data(85).dtTransOffset = 84;

                    ;% UAM_Flight_control_P.RollRateController_UpperSaturat
                    section.data(86).logicalSrcIdx = 95;
                    section.data(86).dtTransOffset = 85;

                    ;% UAM_Flight_control_P.Altituderatecontroller_UpperSat
                    section.data(87).logicalSrcIdx = 96;
                    section.data(87).dtTransOffset = 86;

                    ;% UAM_Flight_control_P.Lateralpositioncontroller_Upper
                    section.data(88).logicalSrcIdx = 97;
                    section.data(88).dtTransOffset = 87;

                    ;% UAM_Flight_control_P.Lateralvelocitycontroller_Upp_b
                    section.data(89).logicalSrcIdx = 98;
                    section.data(89).dtTransOffset = 88;

                    ;% UAM_Flight_control_P.Forwardvelocitycontroller_Upp_o
                    section.data(90).logicalSrcIdx = 99;
                    section.data(90).dtTransOffset = 89;

                    ;% UAM_Flight_control_P.RudderController_UpperSaturat_c
                    section.data(91).logicalSrcIdx = 100;
                    section.data(91).dtTransOffset = 90;

                    ;% UAM_Flight_control_P.PitchAngleController_UpperSat_f
                    section.data(92).logicalSrcIdx = 101;
                    section.data(92).dtTransOffset = 91;

                    ;% UAM_Flight_control_P.PitchRateController_UpperSatu_h
                    section.data(93).logicalSrcIdx = 102;
                    section.data(93).dtTransOffset = 92;

                    ;% UAM_Flight_control_P.RollRateController_UpperSatur_k
                    section.data(94).logicalSrcIdx = 103;
                    section.data(94).dtTransOffset = 93;

                    ;% UAM_Flight_control_P.PitchAngleController_UpperSat_c
                    section.data(95).logicalSrcIdx = 104;
                    section.data(95).dtTransOffset = 94;

                    ;% UAM_Flight_control_P.PitchRateController_UpperSatu_l
                    section.data(96).logicalSrcIdx = 105;
                    section.data(96).dtTransOffset = 95;

                    ;% UAM_Flight_control_P.RudderController_UpperSaturat_i
                    section.data(97).logicalSrcIdx = 106;
                    section.data(97).dtTransOffset = 96;

                    ;% UAM_Flight_control_P.RollRateController_UpperSatur_l
                    section.data(98).logicalSrcIdx = 107;
                    section.data(98).dtTransOffset = 97;

                    ;% UAM_Flight_control_P.CompareToConstant_const
                    section.data(99).logicalSrcIdx = 108;
                    section.data(99).dtTransOffset = 98;

                    ;% UAM_Flight_control_P.CompareToConstant_const_i
                    section.data(100).logicalSrcIdx = 109;
                    section.data(100).dtTransOffset = 99;

                    ;% UAM_Flight_control_P.CompareToConstant1_const
                    section.data(101).logicalSrcIdx = 110;
                    section.data(101).dtTransOffset = 100;

                    ;% UAM_Flight_control_P.deadzone_const
                    section.data(102).logicalSrcIdx = 111;
                    section.data(102).dtTransOffset = 101;

                    ;% UAM_Flight_control_P.disarm_const
                    section.data(103).logicalSrcIdx = 112;
                    section.data(103).dtTransOffset = 102;

                    ;% UAM_Flight_control_P.arm_const
                    section.data(104).logicalSrcIdx = 113;
                    section.data(104).dtTransOffset = 103;

                    ;% UAM_Flight_control_P.CompareToConstant1_const_f
                    section.data(105).logicalSrcIdx = 114;
                    section.data(105).dtTransOffset = 104;

                    ;% UAM_Flight_control_P.CompareToConstant_const_g
                    section.data(106).logicalSrcIdx = 115;
                    section.data(106).dtTransOffset = 105;

                    ;% UAM_Flight_control_P.CompareToConstant_const_d
                    section.data(107).logicalSrcIdx = 116;
                    section.data(107).dtTransOffset = 106;

                    ;% UAM_Flight_control_P.CompareToConstant1_const_i
                    section.data(108).logicalSrcIdx = 117;
                    section.data(108).dtTransOffset = 107;

            nTotData = nTotData + section.nData;
            paramMap.sections(7) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.DetectRisePositive_vinit
                    section.data(1).logicalSrcIdx = 118;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_P.DetectRisePositive1_vinit
                    section.data(2).logicalSrcIdx = 119;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_P.DetectRisePositive_vinit_j
                    section.data(3).logicalSrcIdx = 120;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_P.DetectRisePositive1_vinit_g
                    section.data(4).logicalSrcIdx = 121;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            paramMap.sections(8) = section;
            clear section

            section.nData     = 10;
            section.data(10)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.CompareToConstant_const_a
                    section.data(1).logicalSrcIdx = 122;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_P.prev_is_1_const
                    section.data(2).logicalSrcIdx = 123;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_P.now_is_0_const
                    section.data(3).logicalSrcIdx = 124;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_P.CompareToConstant_const_j
                    section.data(4).logicalSrcIdx = 125;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_P.CompareToConstant1_const_b
                    section.data(5).logicalSrcIdx = 126;
                    section.data(5).dtTransOffset = 4;

                    ;% UAM_Flight_control_P.CompareToConstant_const_p
                    section.data(6).logicalSrcIdx = 127;
                    section.data(6).dtTransOffset = 5;

                    ;% UAM_Flight_control_P.CompareToConstant1_const_ih
                    section.data(7).logicalSrcIdx = 128;
                    section.data(7).dtTransOffset = 6;

                    ;% UAM_Flight_control_P.CompareToConstant_const_e
                    section.data(8).logicalSrcIdx = 129;
                    section.data(8).dtTransOffset = 7;

                    ;% UAM_Flight_control_P.CompareToConstant_const_b
                    section.data(9).logicalSrcIdx = 130;
                    section.data(9).dtTransOffset = 8;

                    ;% UAM_Flight_control_P.CompareToConstant_const_c
                    section.data(10).logicalSrcIdx = 131;
                    section.data(10).dtTransOffset = 9;

            nTotData = nTotData + section.nData;
            paramMap.sections(9) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.UnitDelay_3_InitialCondition
                    section.data(1).logicalSrcIdx = 132;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(10) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.UnitDelay_2_InitialCondition
                    section.data(1).logicalSrcIdx = 133;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(11) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Waypoints2_Value
                    section.data(1).logicalSrcIdx = 134;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(12) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Merge_2_InitialOutput
                    section.data(1).logicalSrcIdx = 135;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(13) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Merge_3_InitialOutput
                    section.data(1).logicalSrcIdx = 136;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(14) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.UnitDelay_6_InitialCondition
                    section.data(1).logicalSrcIdx = 137;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(15) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Constant2_Value
                    section.data(1).logicalSrcIdx = 138;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(16) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.UnitDelay_6_InitialCondition_l
                    section.data(1).logicalSrcIdx = 139;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(17) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.UnitDelay_6_InitialCondition_lw
                    section.data(1).logicalSrcIdx = 140;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(18) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Constant2_Value_i
                    section.data(1).logicalSrcIdx = 141;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(19) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Merge_6_InitialOutput
                    section.data(1).logicalSrcIdx = 142;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(20) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.UnitDelay1_7_InitialCondition
                    section.data(1).logicalSrcIdx = 143;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(21) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Merge_10_InitialOutput
                    section.data(1).logicalSrcIdx = 144;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(22) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.MixerCommands_Y0
                    section.data(1).logicalSrcIdx = 145;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(23) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.MixerCommands_Y0_b
                    section.data(1).logicalSrcIdx = 146;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(24) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.MixerCommands_Y0_e
                    section.data(1).logicalSrcIdx = 147;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(25) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Actuator_Outport_1_Y0
                    section.data(1).logicalSrcIdx = 148;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(26) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Actuator_Outport_1_Y0_d
                    section.data(1).logicalSrcIdx = 149;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(27) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Actuator_Outport_1_Y0_d1
                    section.data(1).logicalSrcIdx = 150;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(28) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Actuator_Outport_1_Y0_d1t
                    section.data(1).logicalSrcIdx = 151;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(29) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.UnitDelay_5_InitialCondition
                    section.data(1).logicalSrcIdx = 152;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(30) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Constant1_Value
                    section.data(1).logicalSrcIdx = 153;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(31) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.UnitDelay_5_InitialCondition_l
                    section.data(1).logicalSrcIdx = 154;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(32) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.UnitDelay_5_InitialCondition_lw
                    section.data(1).logicalSrcIdx = 155;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(33) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Constant1_Value_f
                    section.data(1).logicalSrcIdx = 156;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(34) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Merge_5_InitialOutput
                    section.data(1).logicalSrcIdx = 157;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(35) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.CtrlSurfaceCommands_Y0
                    section.data(1).logicalSrcIdx = 158;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(36) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Merge_InitialOutput
                    section.data(1).logicalSrcIdx = 159;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(37) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.CtrlSurfaceCommands_Y0_a
                    section.data(1).logicalSrcIdx = 160;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(38) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Merge_InitialOutput_i
                    section.data(1).logicalSrcIdx = 161;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(39) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.CtrlSurfaceCommands_Y0_k
                    section.data(1).logicalSrcIdx = 162;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(40) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Merge_InitialOutput_g
                    section.data(1).logicalSrcIdx = 163;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(41) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Merge_52_InitialOutput
                    section.data(1).logicalSrcIdx = 164;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(42) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Actuator_Y0
                    section.data(1).logicalSrcIdx = 165;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(43) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Actuator_Y0_a
                    section.data(1).logicalSrcIdx = 166;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(44) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.UnitDelay_7_InitialCondition
                    section.data(1).logicalSrcIdx = 167;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(45) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.UnitDelay_7_InitialCondition_l
                    section.data(1).logicalSrcIdx = 168;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(46) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.UnitDelay_7_InitialCondition_lw
                    section.data(1).logicalSrcIdx = 169;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(47) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Merge_7_InitialOutput
                    section.data(1).logicalSrcIdx = 170;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(48) = section;
            clear section

            section.nData     = 478;
            section.data(478)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.AER_Y0
                    section.data(1).logicalSrcIdx = 171;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_P.Constant1_Value_l
                    section.data(2).logicalSrcIdx = 172;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_P.Constant_Value
                    section.data(3).logicalSrcIdx = 173;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_P.Integrator_gainval
                    section.data(4).logicalSrcIdx = 174;
                    section.data(4).dtTransOffset = 6;

                    ;% UAM_Flight_control_P.Filter_gainval
                    section.data(5).logicalSrcIdx = 175;
                    section.data(5).dtTransOffset = 7;

                    ;% UAM_Flight_control_P.Saturation2_UpperSat
                    section.data(6).logicalSrcIdx = 176;
                    section.data(6).dtTransOffset = 8;

                    ;% UAM_Flight_control_P.Saturation2_LowerSat
                    section.data(7).logicalSrcIdx = 177;
                    section.data(7).dtTransOffset = 9;

                    ;% UAM_Flight_control_P.Clamping_zero_Value
                    section.data(8).logicalSrcIdx = 178;
                    section.data(8).dtTransOffset = 10;

                    ;% UAM_Flight_control_P.Bias_Bias
                    section.data(9).logicalSrcIdx = 179;
                    section.data(9).dtTransOffset = 11;

                    ;% UAM_Flight_control_P.Gain_Gain
                    section.data(10).logicalSrcIdx = 180;
                    section.data(10).dtTransOffset = 12;

                    ;% UAM_Flight_control_P.Gain1_Gain
                    section.data(11).logicalSrcIdx = 181;
                    section.data(11).dtTransOffset = 13;

                    ;% UAM_Flight_control_P.Bias_Bias_k
                    section.data(12).logicalSrcIdx = 182;
                    section.data(12).dtTransOffset = 14;

                    ;% UAM_Flight_control_P.Gain_Gain_g
                    section.data(13).logicalSrcIdx = 183;
                    section.data(13).dtTransOffset = 15;

                    ;% UAM_Flight_control_P.Gain1_Gain_d
                    section.data(14).logicalSrcIdx = 184;
                    section.data(14).dtTransOffset = 16;

                    ;% UAM_Flight_control_P.Constant_Value_m
                    section.data(15).logicalSrcIdx = 185;
                    section.data(15).dtTransOffset = 17;

                    ;% UAM_Flight_control_P.Constant4_Value
                    section.data(16).logicalSrcIdx = 186;
                    section.data(16).dtTransOffset = 33;

                    ;% UAM_Flight_control_P.MotorActuatorCommands_Y0
                    section.data(17).logicalSrcIdx = 187;
                    section.data(17).dtTransOffset = 34;

                    ;% UAM_Flight_control_P.Gain1_Gain_e
                    section.data(18).logicalSrcIdx = 188;
                    section.data(18).dtTransOffset = 35;

                    ;% UAM_Flight_control_P.Constant2_Value_j
                    section.data(19).logicalSrcIdx = 189;
                    section.data(19).dtTransOffset = 36;

                    ;% UAM_Flight_control_P.Gain3_Gain
                    section.data(20).logicalSrcIdx = 190;
                    section.data(20).dtTransOffset = 37;

                    ;% UAM_Flight_control_P.Constant4_Value_i
                    section.data(21).logicalSrcIdx = 191;
                    section.data(21).dtTransOffset = 38;

                    ;% UAM_Flight_control_P.Gain5_Gain
                    section.data(22).logicalSrcIdx = 192;
                    section.data(22).dtTransOffset = 39;

                    ;% UAM_Flight_control_P.Constant6_Value
                    section.data(23).logicalSrcIdx = 193;
                    section.data(23).dtTransOffset = 40;

                    ;% UAM_Flight_control_P.Gain7_Gain
                    section.data(24).logicalSrcIdx = 194;
                    section.data(24).dtTransOffset = 41;

                    ;% UAM_Flight_control_P.Constant8_Value
                    section.data(25).logicalSrcIdx = 195;
                    section.data(25).dtTransOffset = 42;

                    ;% UAM_Flight_control_P.Constant_Value_d
                    section.data(26).logicalSrcIdx = 196;
                    section.data(26).dtTransOffset = 43;

                    ;% UAM_Flight_control_P.Saturation_UpperSat
                    section.data(27).logicalSrcIdx = 197;
                    section.data(27).dtTransOffset = 44;

                    ;% UAM_Flight_control_P.Saturation_LowerSat
                    section.data(28).logicalSrcIdx = 198;
                    section.data(28).dtTransOffset = 45;

                    ;% UAM_Flight_control_P.Saturation1_UpperSat
                    section.data(29).logicalSrcIdx = 199;
                    section.data(29).dtTransOffset = 46;

                    ;% UAM_Flight_control_P.Saturation1_LowerSat
                    section.data(30).logicalSrcIdx = 200;
                    section.data(30).dtTransOffset = 47;

                    ;% UAM_Flight_control_P.Saturation2_UpperSat_b
                    section.data(31).logicalSrcIdx = 201;
                    section.data(31).dtTransOffset = 48;

                    ;% UAM_Flight_control_P.Saturation2_LowerSat_n
                    section.data(32).logicalSrcIdx = 202;
                    section.data(32).dtTransOffset = 49;

                    ;% UAM_Flight_control_P.Saturation3_UpperSat
                    section.data(33).logicalSrcIdx = 203;
                    section.data(33).dtTransOffset = 50;

                    ;% UAM_Flight_control_P.Saturation3_LowerSat
                    section.data(34).logicalSrcIdx = 204;
                    section.data(34).dtTransOffset = 51;

                    ;% UAM_Flight_control_P.Saturation4_UpperSat
                    section.data(35).logicalSrcIdx = 205;
                    section.data(35).dtTransOffset = 52;

                    ;% UAM_Flight_control_P.Saturation4_LowerSat
                    section.data(36).logicalSrcIdx = 206;
                    section.data(36).dtTransOffset = 53;

                    ;% UAM_Flight_control_P.throttle_up_Gain
                    section.data(37).logicalSrcIdx = 207;
                    section.data(37).dtTransOffset = 54;

                    ;% UAM_Flight_control_P.throttle_down_Gain
                    section.data(38).logicalSrcIdx = 208;
                    section.data(38).dtTransOffset = 55;

                    ;% UAM_Flight_control_P.Switch_Threshold
                    section.data(39).logicalSrcIdx = 209;
                    section.data(39).dtTransOffset = 56;

                    ;% UAM_Flight_control_P.Constant1_Value_p
                    section.data(40).logicalSrcIdx = 210;
                    section.data(40).dtTransOffset = 57;

                    ;% UAM_Flight_control_P.Gain_Gain_b
                    section.data(41).logicalSrcIdx = 211;
                    section.data(41).dtTransOffset = 58;

                    ;% UAM_Flight_control_P.Bias_Bias_h
                    section.data(42).logicalSrcIdx = 212;
                    section.data(42).dtTransOffset = 59;

                    ;% UAM_Flight_control_P.Gain3_Gain_h
                    section.data(43).logicalSrcIdx = 213;
                    section.data(43).dtTransOffset = 60;

                    ;% UAM_Flight_control_P.DeadZone_Start
                    section.data(44).logicalSrcIdx = 214;
                    section.data(44).dtTransOffset = 61;

                    ;% UAM_Flight_control_P.DeadZone_End
                    section.data(45).logicalSrcIdx = 215;
                    section.data(45).dtTransOffset = 62;

                    ;% UAM_Flight_control_P.Constant_Value_o
                    section.data(46).logicalSrcIdx = 216;
                    section.data(46).dtTransOffset = 63;

                    ;% UAM_Flight_control_P.UnitDelay_InitialCondition
                    section.data(47).logicalSrcIdx = 217;
                    section.data(47).dtTransOffset = 64;

                    ;% UAM_Flight_control_P.Gain1_Gain_p
                    section.data(48).logicalSrcIdx = 218;
                    section.data(48).dtTransOffset = 65;

                    ;% UAM_Flight_control_P.Integrator_gainval_n
                    section.data(49).logicalSrcIdx = 219;
                    section.data(49).dtTransOffset = 66;

                    ;% UAM_Flight_control_P.Filter_gainval_e
                    section.data(50).logicalSrcIdx = 220;
                    section.data(50).dtTransOffset = 67;

                    ;% UAM_Flight_control_P.UnitDelay_InitialCondition_k
                    section.data(51).logicalSrcIdx = 221;
                    section.data(51).dtTransOffset = 68;

                    ;% UAM_Flight_control_P.hover_thrustg_Gain
                    section.data(52).logicalSrcIdx = 222;
                    section.data(52).dtTransOffset = 69;

                    ;% UAM_Flight_control_P.Saturation1_UpperSat_p
                    section.data(53).logicalSrcIdx = 223;
                    section.data(53).dtTransOffset = 70;

                    ;% UAM_Flight_control_P.Saturation1_LowerSat_i
                    section.data(54).logicalSrcIdx = 224;
                    section.data(54).dtTransOffset = 71;

                    ;% UAM_Flight_control_P.Clamping_zero_Value_n
                    section.data(55).logicalSrcIdx = 225;
                    section.data(55).dtTransOffset = 72;

                    ;% UAM_Flight_control_P.yaw_max_rate_Gain
                    section.data(56).logicalSrcIdx = 226;
                    section.data(56).dtTransOffset = 73;

                    ;% UAM_Flight_control_P.FowardVelocitySetpoint_UpperSat
                    section.data(57).logicalSrcIdx = 227;
                    section.data(57).dtTransOffset = 74;

                    ;% UAM_Flight_control_P.FowardVelocitySetpoint_LowerSat
                    section.data(58).logicalSrcIdx = 228;
                    section.data(58).dtTransOffset = 75;

                    ;% UAM_Flight_control_P.Vel_manual_Gain
                    section.data(59).logicalSrcIdx = 229;
                    section.data(59).dtTransOffset = 76;

                    ;% UAM_Flight_control_P.LateralVelocitySetpoint_UpperSa
                    section.data(60).logicalSrcIdx = 230;
                    section.data(60).dtTransOffset = 77;

                    ;% UAM_Flight_control_P.LateralVelocitySetpoint_LowerSa
                    section.data(61).logicalSrcIdx = 231;
                    section.data(61).dtTransOffset = 78;

                    ;% UAM_Flight_control_P.Vel_manualms_Gain
                    section.data(62).logicalSrcIdx = 232;
                    section.data(62).dtTransOffset = 79;

                    ;% UAM_Flight_control_P.Constant1_Value_g
                    section.data(63).logicalSrcIdx = 233;
                    section.data(63).dtTransOffset = 80;

                    ;% UAM_Flight_control_P.Constant1_Value_h
                    section.data(64).logicalSrcIdx = 234;
                    section.data(64).dtTransOffset = 81;

                    ;% UAM_Flight_control_P.Gain_Gain_i
                    section.data(65).logicalSrcIdx = 235;
                    section.data(65).dtTransOffset = 82;

                    ;% UAM_Flight_control_P.DeadZone_Start_b
                    section.data(66).logicalSrcIdx = 236;
                    section.data(66).dtTransOffset = 83;

                    ;% UAM_Flight_control_P.DeadZone_End_h
                    section.data(67).logicalSrcIdx = 237;
                    section.data(67).dtTransOffset = 84;

                    ;% UAM_Flight_control_P.Constant_Value_k
                    section.data(68).logicalSrcIdx = 238;
                    section.data(68).dtTransOffset = 85;

                    ;% UAM_Flight_control_P.DeadZone1_Start
                    section.data(69).logicalSrcIdx = 239;
                    section.data(69).dtTransOffset = 86;

                    ;% UAM_Flight_control_P.DeadZone1_End
                    section.data(70).logicalSrcIdx = 240;
                    section.data(70).dtTransOffset = 87;

                    ;% UAM_Flight_control_P.Constant1_Value_o
                    section.data(71).logicalSrcIdx = 241;
                    section.data(71).dtTransOffset = 88;

                    ;% UAM_Flight_control_P.UnitDelay_InitialCondition_o
                    section.data(72).logicalSrcIdx = 242;
                    section.data(72).dtTransOffset = 89;

                    ;% UAM_Flight_control_P.Gain_Gain_i2
                    section.data(73).logicalSrcIdx = 243;
                    section.data(73).dtTransOffset = 90;

                    ;% UAM_Flight_control_P.UnitDelay1_InitialCondition
                    section.data(74).logicalSrcIdx = 244;
                    section.data(74).dtTransOffset = 91;

                    ;% UAM_Flight_control_P.Constant2_Value_n
                    section.data(75).logicalSrcIdx = 245;
                    section.data(75).dtTransOffset = 92;

                    ;% UAM_Flight_control_P.RateLimiter_RisingLim
                    section.data(76).logicalSrcIdx = 246;
                    section.data(76).dtTransOffset = 93;

                    ;% UAM_Flight_control_P.RateLimiter_FallingLim
                    section.data(77).logicalSrcIdx = 247;
                    section.data(77).dtTransOffset = 94;

                    ;% UAM_Flight_control_P.RateLimiter_IC
                    section.data(78).logicalSrcIdx = 248;
                    section.data(78).dtTransOffset = 95;

                    ;% UAM_Flight_control_P.Integrator_gainval_d
                    section.data(79).logicalSrcIdx = 249;
                    section.data(79).dtTransOffset = 96;

                    ;% UAM_Flight_control_P.Filter_gainval_i
                    section.data(80).logicalSrcIdx = 250;
                    section.data(80).dtTransOffset = 97;

                    ;% UAM_Flight_control_P.Clamping_zero_Value_b
                    section.data(81).logicalSrcIdx = 251;
                    section.data(81).dtTransOffset = 98;

                    ;% UAM_Flight_control_P.rad_Gain
                    section.data(82).logicalSrcIdx = 252;
                    section.data(82).dtTransOffset = 99;

                    ;% UAM_Flight_control_P.Saturation1_UpperSat_a
                    section.data(83).logicalSrcIdx = 253;
                    section.data(83).dtTransOffset = 100;

                    ;% UAM_Flight_control_P.Saturation1_LowerSat_m
                    section.data(84).logicalSrcIdx = 254;
                    section.data(84).dtTransOffset = 101;

                    ;% UAM_Flight_control_P.RateLimiter1_RisingLim
                    section.data(85).logicalSrcIdx = 255;
                    section.data(85).dtTransOffset = 102;

                    ;% UAM_Flight_control_P.RateLimiter1_FallingLim
                    section.data(86).logicalSrcIdx = 256;
                    section.data(86).dtTransOffset = 103;

                    ;% UAM_Flight_control_P.RateLimiter1_IC
                    section.data(87).logicalSrcIdx = 257;
                    section.data(87).dtTransOffset = 104;

                    ;% UAM_Flight_control_P.Integrator_gainval_i
                    section.data(88).logicalSrcIdx = 258;
                    section.data(88).dtTransOffset = 105;

                    ;% UAM_Flight_control_P.Filter_gainval_j
                    section.data(89).logicalSrcIdx = 259;
                    section.data(89).dtTransOffset = 106;

                    ;% UAM_Flight_control_P.Clamping_zero_Value_p
                    section.data(90).logicalSrcIdx = 260;
                    section.data(90).dtTransOffset = 107;

                    ;% UAM_Flight_control_P.Gain_Gain_j
                    section.data(91).logicalSrcIdx = 261;
                    section.data(91).dtTransOffset = 108;

                    ;% UAM_Flight_control_P.Saturation_UpperSat_e
                    section.data(92).logicalSrcIdx = 262;
                    section.data(92).dtTransOffset = 109;

                    ;% UAM_Flight_control_P.Saturation_LowerSat_f
                    section.data(93).logicalSrcIdx = 263;
                    section.data(93).dtTransOffset = 110;

                    ;% UAM_Flight_control_P.Bias1_Bias
                    section.data(94).logicalSrcIdx = 264;
                    section.data(94).dtTransOffset = 111;

                    ;% UAM_Flight_control_P.Gain1_Gain_k
                    section.data(95).logicalSrcIdx = 265;
                    section.data(95).dtTransOffset = 112;

                    ;% UAM_Flight_control_P.Saturation_UpperSat_f
                    section.data(96).logicalSrcIdx = 266;
                    section.data(96).dtTransOffset = 113;

                    ;% UAM_Flight_control_P.Saturation_LowerSat_e
                    section.data(97).logicalSrcIdx = 267;
                    section.data(97).dtTransOffset = 114;

                    ;% UAM_Flight_control_P.Merge2_InitialOutput
                    section.data(98).logicalSrcIdx = 268;
                    section.data(98).dtTransOffset = 115;

                    ;% UAM_Flight_control_P.Bias_Bias_j
                    section.data(99).logicalSrcIdx = 269;
                    section.data(99).dtTransOffset = 116;

                    ;% UAM_Flight_control_P.Gain_Gain_c
                    section.data(100).logicalSrcIdx = 270;
                    section.data(100).dtTransOffset = 117;

                    ;% UAM_Flight_control_P.RefRP_InitialOutput
                    section.data(101).logicalSrcIdx = 271;
                    section.data(101).dtTransOffset = 118;

                    ;% UAM_Flight_control_P.UnitDelay1_InitialCondition_p
                    section.data(102).logicalSrcIdx = 272;
                    section.data(102).dtTransOffset = 119;

                    ;% UAM_Flight_control_P.Integrator_gainval_du
                    section.data(103).logicalSrcIdx = 273;
                    section.data(103).dtTransOffset = 120;

                    ;% UAM_Flight_control_P.Gain1_Gain_k5
                    section.data(104).logicalSrcIdx = 274;
                    section.data(104).dtTransOffset = 121;

                    ;% UAM_Flight_control_P.Pitch_MAX_angle_Gain
                    section.data(105).logicalSrcIdx = 275;
                    section.data(105).dtTransOffset = 122;

                    ;% UAM_Flight_control_P.Saturation1_UpperSat_g
                    section.data(106).logicalSrcIdx = 276;
                    section.data(106).dtTransOffset = 123;

                    ;% UAM_Flight_control_P.Saturation1_LowerSat_b
                    section.data(107).logicalSrcIdx = 277;
                    section.data(107).dtTransOffset = 124;

                    ;% UAM_Flight_control_P.Filter_gainval_p
                    section.data(108).logicalSrcIdx = 278;
                    section.data(108).dtTransOffset = 125;

                    ;% UAM_Flight_control_P.Integrator_gainval_m
                    section.data(109).logicalSrcIdx = 279;
                    section.data(109).dtTransOffset = 126;

                    ;% UAM_Flight_control_P.Roll_MAX_angle_Gain
                    section.data(110).logicalSrcIdx = 280;
                    section.data(110).dtTransOffset = 127;

                    ;% UAM_Flight_control_P.Saturation_UpperSat_d
                    section.data(111).logicalSrcIdx = 281;
                    section.data(111).dtTransOffset = 128;

                    ;% UAM_Flight_control_P.Saturation_LowerSat_p
                    section.data(112).logicalSrcIdx = 282;
                    section.data(112).dtTransOffset = 129;

                    ;% UAM_Flight_control_P.Filter_gainval_c
                    section.data(113).logicalSrcIdx = 283;
                    section.data(113).dtTransOffset = 130;

                    ;% UAM_Flight_control_P.Integrator_gainval_o
                    section.data(114).logicalSrcIdx = 284;
                    section.data(114).dtTransOffset = 131;

                    ;% UAM_Flight_control_P.Saturation5_UpperSat
                    section.data(115).logicalSrcIdx = 285;
                    section.data(115).dtTransOffset = 132;

                    ;% UAM_Flight_control_P.Saturation5_LowerSat
                    section.data(116).logicalSrcIdx = 286;
                    section.data(116).dtTransOffset = 133;

                    ;% UAM_Flight_control_P.Saturation_UpperSat_n
                    section.data(117).logicalSrcIdx = 287;
                    section.data(117).dtTransOffset = 134;

                    ;% UAM_Flight_control_P.Saturation_LowerSat_b
                    section.data(118).logicalSrcIdx = 288;
                    section.data(118).dtTransOffset = 135;

                    ;% UAM_Flight_control_P.Constant6_Value_e
                    section.data(119).logicalSrcIdx = 289;
                    section.data(119).dtTransOffset = 136;

                    ;% UAM_Flight_control_P.Constant5_Value
                    section.data(120).logicalSrcIdx = 290;
                    section.data(120).dtTransOffset = 137;

                    ;% UAM_Flight_control_P.Gain3_Gain_a
                    section.data(121).logicalSrcIdx = 291;
                    section.data(121).dtTransOffset = 138;

                    ;% UAM_Flight_control_P.Constant3_Value
                    section.data(122).logicalSrcIdx = 292;
                    section.data(122).dtTransOffset = 139;

                    ;% UAM_Flight_control_P.Saturation1_UpperSat_az
                    section.data(123).logicalSrcIdx = 293;
                    section.data(123).dtTransOffset = 140;

                    ;% UAM_Flight_control_P.Saturation1_LowerSat_p
                    section.data(124).logicalSrcIdx = 294;
                    section.data(124).dtTransOffset = 141;

                    ;% UAM_Flight_control_P.Gain3_Gain_hy
                    section.data(125).logicalSrcIdx = 295;
                    section.data(125).dtTransOffset = 142;

                    ;% UAM_Flight_control_P.Constant_Value_n
                    section.data(126).logicalSrcIdx = 296;
                    section.data(126).dtTransOffset = 143;

                    ;% UAM_Flight_control_P.Gain_Gain_o
                    section.data(127).logicalSrcIdx = 297;
                    section.data(127).dtTransOffset = 144;

                    ;% UAM_Flight_control_P.Saturation_UpperSat_p
                    section.data(128).logicalSrcIdx = 298;
                    section.data(128).dtTransOffset = 145;

                    ;% UAM_Flight_control_P.Saturation_LowerSat_d
                    section.data(129).logicalSrcIdx = 299;
                    section.data(129).dtTransOffset = 146;

                    ;% UAM_Flight_control_P.ClimbRateSPMerge_InitialOutput
                    section.data(130).logicalSrcIdx = 300;
                    section.data(130).dtTransOffset = 147;

                    ;% UAM_Flight_control_P.Gain_Gain_jq
                    section.data(131).logicalSrcIdx = 301;
                    section.data(131).dtTransOffset = 148;

                    ;% UAM_Flight_control_P.Filter_gainval_cg
                    section.data(132).logicalSrcIdx = 302;
                    section.data(132).dtTransOffset = 149;

                    ;% UAM_Flight_control_P.Integrator_gainval_f
                    section.data(133).logicalSrcIdx = 303;
                    section.data(133).dtTransOffset = 150;

                    ;% UAM_Flight_control_P.Constant1_Value_a
                    section.data(134).logicalSrcIdx = 304;
                    section.data(134).dtTransOffset = 151;

                    ;% UAM_Flight_control_P.Integrator_gainval_or
                    section.data(135).logicalSrcIdx = 305;
                    section.data(135).dtTransOffset = 152;

                    ;% UAM_Flight_control_P.Filter_gainval_b
                    section.data(136).logicalSrcIdx = 306;
                    section.data(136).dtTransOffset = 153;

                    ;% UAM_Flight_control_P.Gain2_Gain
                    section.data(137).logicalSrcIdx = 307;
                    section.data(137).dtTransOffset = 154;

                    ;% UAM_Flight_control_P.Gain1_Gain_f
                    section.data(138).logicalSrcIdx = 308;
                    section.data(138).dtTransOffset = 155;

                    ;% UAM_Flight_control_P.Saturation2_UpperSat_n
                    section.data(139).logicalSrcIdx = 309;
                    section.data(139).dtTransOffset = 156;

                    ;% UAM_Flight_control_P.Saturation2_LowerSat_i
                    section.data(140).logicalSrcIdx = 310;
                    section.data(140).dtTransOffset = 157;

                    ;% UAM_Flight_control_P.Clamping_zero_Value_m
                    section.data(141).logicalSrcIdx = 311;
                    section.data(141).dtTransOffset = 158;

                    ;% UAM_Flight_control_P.Constant_Value_g
                    section.data(142).logicalSrcIdx = 312;
                    section.data(142).dtTransOffset = 159;

                    ;% UAM_Flight_control_P.Constant1_Value_b
                    section.data(143).logicalSrcIdx = 313;
                    section.data(143).dtTransOffset = 160;

                    ;% UAM_Flight_control_P.Filter_gainval_m
                    section.data(144).logicalSrcIdx = 314;
                    section.data(144).dtTransOffset = 161;

                    ;% UAM_Flight_control_P.Integrator_gainval_p
                    section.data(145).logicalSrcIdx = 315;
                    section.data(145).dtTransOffset = 162;

                    ;% UAM_Flight_control_P.IC_Value
                    section.data(146).logicalSrcIdx = 316;
                    section.data(146).dtTransOffset = 163;

                    ;% UAM_Flight_control_P.PitchSPMerge_InitialOutput
                    section.data(147).logicalSrcIdx = 317;
                    section.data(147).dtTransOffset = 164;

                    ;% UAM_Flight_control_P.RollSPMerge_InitialOutput
                    section.data(148).logicalSrcIdx = 318;
                    section.data(148).dtTransOffset = 165;

                    ;% UAM_Flight_control_P.ActuatordTMerge_InitialOutput
                    section.data(149).logicalSrcIdx = 319;
                    section.data(149).dtTransOffset = 166;

                    ;% UAM_Flight_control_P.Merge_InitialOutput_n
                    section.data(150).logicalSrcIdx = 320;
                    section.data(150).dtTransOffset = 167;

                    ;% UAM_Flight_control_P.Constant_Value_p
                    section.data(151).logicalSrcIdx = 321;
                    section.data(151).dtTransOffset = 168;

                    ;% UAM_Flight_control_P.Reference_Y0
                    section.data(152).logicalSrcIdx = 322;
                    section.data(152).dtTransOffset = 169;

                    ;% UAM_Flight_control_P.Constant_Value_ob
                    section.data(153).logicalSrcIdx = 323;
                    section.data(153).dtTransOffset = 170;

                    ;% UAM_Flight_control_P.Gain_Gain_iz
                    section.data(154).logicalSrcIdx = 324;
                    section.data(154).dtTransOffset = 171;

                    ;% UAM_Flight_control_P.Integrator_gainval_a
                    section.data(155).logicalSrcIdx = 325;
                    section.data(155).dtTransOffset = 172;

                    ;% UAM_Flight_control_P.Filter_gainval_l
                    section.data(156).logicalSrcIdx = 326;
                    section.data(156).dtTransOffset = 173;

                    ;% UAM_Flight_control_P.Gain_Gain_g4
                    section.data(157).logicalSrcIdx = 327;
                    section.data(157).dtTransOffset = 174;

                    ;% UAM_Flight_control_P.Integrator_gainval_pi
                    section.data(158).logicalSrcIdx = 328;
                    section.data(158).dtTransOffset = 175;

                    ;% UAM_Flight_control_P.Filter_gainval_jo
                    section.data(159).logicalSrcIdx = 329;
                    section.data(159).dtTransOffset = 176;

                    ;% UAM_Flight_control_P.Saturation_UpperSat_nf
                    section.data(160).logicalSrcIdx = 330;
                    section.data(160).dtTransOffset = 177;

                    ;% UAM_Flight_control_P.Saturation_LowerSat_n
                    section.data(161).logicalSrcIdx = 331;
                    section.data(161).dtTransOffset = 178;

                    ;% UAM_Flight_control_P.Constant1_Value_lc
                    section.data(162).logicalSrcIdx = 332;
                    section.data(162).dtTransOffset = 179;

                    ;% UAM_Flight_control_P.Integrator_gainval_e
                    section.data(163).logicalSrcIdx = 333;
                    section.data(163).dtTransOffset = 180;

                    ;% UAM_Flight_control_P.Filter_gainval_n
                    section.data(164).logicalSrcIdx = 334;
                    section.data(164).dtTransOffset = 181;

                    ;% UAM_Flight_control_P.Integrator_gainval_k
                    section.data(165).logicalSrcIdx = 335;
                    section.data(165).dtTransOffset = 182;

                    ;% UAM_Flight_control_P.Filter_gainval_o
                    section.data(166).logicalSrcIdx = 336;
                    section.data(166).dtTransOffset = 183;

                    ;% UAM_Flight_control_P.Saturation1_UpperSat_m
                    section.data(167).logicalSrcIdx = 337;
                    section.data(167).dtTransOffset = 184;

                    ;% UAM_Flight_control_P.Saturation1_LowerSat_mv
                    section.data(168).logicalSrcIdx = 338;
                    section.data(168).dtTransOffset = 185;

                    ;% UAM_Flight_control_P.Constant_Value_f
                    section.data(169).logicalSrcIdx = 339;
                    section.data(169).dtTransOffset = 186;

                    ;% UAM_Flight_control_P.Constant1_Value_lv
                    section.data(170).logicalSrcIdx = 340;
                    section.data(170).dtTransOffset = 187;

                    ;% UAM_Flight_control_P.Gain_Gain_f
                    section.data(171).logicalSrcIdx = 341;
                    section.data(171).dtTransOffset = 188;

                    ;% UAM_Flight_control_P.Gain1_Gain_a
                    section.data(172).logicalSrcIdx = 342;
                    section.data(172).dtTransOffset = 189;

                    ;% UAM_Flight_control_P.RateLimiter_RisingLim_g
                    section.data(173).logicalSrcIdx = 343;
                    section.data(173).dtTransOffset = 190;

                    ;% UAM_Flight_control_P.RateLimiter_FallingLim_o
                    section.data(174).logicalSrcIdx = 344;
                    section.data(174).dtTransOffset = 191;

                    ;% UAM_Flight_control_P.RateLimiter_IC_p
                    section.data(175).logicalSrcIdx = 345;
                    section.data(175).dtTransOffset = 192;

                    ;% UAM_Flight_control_P.Filter_gainval_k
                    section.data(176).logicalSrcIdx = 346;
                    section.data(176).dtTransOffset = 193;

                    ;% UAM_Flight_control_P.Integrator_gainval_nh
                    section.data(177).logicalSrcIdx = 347;
                    section.data(177).dtTransOffset = 194;

                    ;% UAM_Flight_control_P.Filter_gainval_ob
                    section.data(178).logicalSrcIdx = 348;
                    section.data(178).dtTransOffset = 195;

                    ;% UAM_Flight_control_P.Integrator_gainval_j
                    section.data(179).logicalSrcIdx = 349;
                    section.data(179).dtTransOffset = 196;

                    ;% UAM_Flight_control_P.Gain_Gain_d
                    section.data(180).logicalSrcIdx = 350;
                    section.data(180).dtTransOffset = 197;

                    ;% UAM_Flight_control_P.Gain1_Gain_m
                    section.data(181).logicalSrcIdx = 351;
                    section.data(181).dtTransOffset = 198;

                    ;% UAM_Flight_control_P.Gain2_Gain_p
                    section.data(182).logicalSrcIdx = 352;
                    section.data(182).dtTransOffset = 199;

                    ;% UAM_Flight_control_P.Merge_InitialOutput_k
                    section.data(183).logicalSrcIdx = 353;
                    section.data(183).dtTransOffset = 200;

                    ;% UAM_Flight_control_P.Merge1_InitialOutput
                    section.data(184).logicalSrcIdx = 354;
                    section.data(184).dtTransOffset = 201;

                    ;% UAM_Flight_control_P.Filter_gainval_nu
                    section.data(185).logicalSrcIdx = 355;
                    section.data(185).dtTransOffset = 202;

                    ;% UAM_Flight_control_P.Integrator_gainval_fu
                    section.data(186).logicalSrcIdx = 356;
                    section.data(186).dtTransOffset = 203;

                    ;% UAM_Flight_control_P.Filter_gainval_eq
                    section.data(187).logicalSrcIdx = 357;
                    section.data(187).dtTransOffset = 204;

                    ;% UAM_Flight_control_P.Integrator_gainval_mq
                    section.data(188).logicalSrcIdx = 358;
                    section.data(188).dtTransOffset = 205;

                    ;% UAM_Flight_control_P.Filter_gainval_kq
                    section.data(189).logicalSrcIdx = 359;
                    section.data(189).dtTransOffset = 206;

                    ;% UAM_Flight_control_P.Integrator_gainval_iq
                    section.data(190).logicalSrcIdx = 360;
                    section.data(190).dtTransOffset = 207;

                    ;% UAM_Flight_control_P.Filter_gainval_f
                    section.data(191).logicalSrcIdx = 361;
                    section.data(191).dtTransOffset = 208;

                    ;% UAM_Flight_control_P.Integrator_gainval_c
                    section.data(192).logicalSrcIdx = 362;
                    section.data(192).dtTransOffset = 209;

                    ;% UAM_Flight_control_P.Integrator_gainval_cd
                    section.data(193).logicalSrcIdx = 363;
                    section.data(193).dtTransOffset = 210;

                    ;% UAM_Flight_control_P.Filter_gainval_ez
                    section.data(194).logicalSrcIdx = 364;
                    section.data(194).dtTransOffset = 211;

                    ;% UAM_Flight_control_P.Filter_gainval_oy
                    section.data(195).logicalSrcIdx = 365;
                    section.data(195).dtTransOffset = 212;

                    ;% UAM_Flight_control_P.Integrator_gainval_b
                    section.data(196).logicalSrcIdx = 366;
                    section.data(196).dtTransOffset = 213;

                    ;% UAM_Flight_control_P.Constant6_Value_h
                    section.data(197).logicalSrcIdx = 367;
                    section.data(197).dtTransOffset = 214;

                    ;% UAM_Flight_control_P.Constant4_Value_j
                    section.data(198).logicalSrcIdx = 368;
                    section.data(198).dtTransOffset = 215;

                    ;% UAM_Flight_control_P.Constant5_Value_e
                    section.data(199).logicalSrcIdx = 369;
                    section.data(199).dtTransOffset = 216;

                    ;% UAM_Flight_control_P.Saturation6_UpperSat
                    section.data(200).logicalSrcIdx = 370;
                    section.data(200).dtTransOffset = 217;

                    ;% UAM_Flight_control_P.Saturation6_LowerSat
                    section.data(201).logicalSrcIdx = 371;
                    section.data(201).dtTransOffset = 218;

                    ;% UAM_Flight_control_P.Saturation4_UpperSat_b
                    section.data(202).logicalSrcIdx = 372;
                    section.data(202).dtTransOffset = 219;

                    ;% UAM_Flight_control_P.Saturation4_LowerSat_g
                    section.data(203).logicalSrcIdx = 373;
                    section.data(203).dtTransOffset = 220;

                    ;% UAM_Flight_control_P.Saturation_UpperSat_po
                    section.data(204).logicalSrcIdx = 374;
                    section.data(204).dtTransOffset = 221;

                    ;% UAM_Flight_control_P.Saturation_LowerSat_k
                    section.data(205).logicalSrcIdx = 375;
                    section.data(205).dtTransOffset = 222;

                    ;% UAM_Flight_control_P.Saturation2_UpperSat_l
                    section.data(206).logicalSrcIdx = 376;
                    section.data(206).dtTransOffset = 223;

                    ;% UAM_Flight_control_P.Saturation2_LowerSat_b
                    section.data(207).logicalSrcIdx = 377;
                    section.data(207).dtTransOffset = 224;

                    ;% UAM_Flight_control_P.Saturation7_UpperSat
                    section.data(208).logicalSrcIdx = 378;
                    section.data(208).dtTransOffset = 225;

                    ;% UAM_Flight_control_P.Saturation7_LowerSat
                    section.data(209).logicalSrcIdx = 379;
                    section.data(209).dtTransOffset = 226;

                    ;% UAM_Flight_control_P.Saturation1_UpperSat_o
                    section.data(210).logicalSrcIdx = 380;
                    section.data(210).dtTransOffset = 227;

                    ;% UAM_Flight_control_P.Saturation1_LowerSat_f
                    section.data(211).logicalSrcIdx = 381;
                    section.data(211).dtTransOffset = 228;

                    ;% UAM_Flight_control_P.Saturation5_UpperSat_j
                    section.data(212).logicalSrcIdx = 382;
                    section.data(212).dtTransOffset = 229;

                    ;% UAM_Flight_control_P.Saturation5_LowerSat_f
                    section.data(213).logicalSrcIdx = 383;
                    section.data(213).dtTransOffset = 230;

                    ;% UAM_Flight_control_P.Saturation3_UpperSat_j
                    section.data(214).logicalSrcIdx = 384;
                    section.data(214).dtTransOffset = 231;

                    ;% UAM_Flight_control_P.Saturation3_LowerSat_b
                    section.data(215).logicalSrcIdx = 385;
                    section.data(215).dtTransOffset = 232;

                    ;% UAM_Flight_control_P.Constant4_Value_d
                    section.data(216).logicalSrcIdx = 386;
                    section.data(216).dtTransOffset = 233;

                    ;% UAM_Flight_control_P.Saturation2_UpperSat_l3
                    section.data(217).logicalSrcIdx = 387;
                    section.data(217).dtTransOffset = 234;

                    ;% UAM_Flight_control_P.Saturation2_LowerSat_f
                    section.data(218).logicalSrcIdx = 388;
                    section.data(218).dtTransOffset = 235;

                    ;% UAM_Flight_control_P.Saturation1_UpperSat_pr
                    section.data(219).logicalSrcIdx = 389;
                    section.data(219).dtTransOffset = 236;

                    ;% UAM_Flight_control_P.Saturation1_LowerSat_k
                    section.data(220).logicalSrcIdx = 390;
                    section.data(220).dtTransOffset = 237;

                    ;% UAM_Flight_control_P.Saturation3_UpperSat_h
                    section.data(221).logicalSrcIdx = 391;
                    section.data(221).dtTransOffset = 238;

                    ;% UAM_Flight_control_P.Saturation3_LowerSat_d
                    section.data(222).logicalSrcIdx = 392;
                    section.data(222).dtTransOffset = 239;

                    ;% UAM_Flight_control_P.Saturation4_UpperSat_e
                    section.data(223).logicalSrcIdx = 393;
                    section.data(223).dtTransOffset = 240;

                    ;% UAM_Flight_control_P.Saturation4_LowerSat_l
                    section.data(224).logicalSrcIdx = 394;
                    section.data(224).dtTransOffset = 241;

                    ;% UAM_Flight_control_P.Saturation4_UpperSat_f
                    section.data(225).logicalSrcIdx = 395;
                    section.data(225).dtTransOffset = 242;

                    ;% UAM_Flight_control_P.Saturation4_LowerSat_p
                    section.data(226).logicalSrcIdx = 396;
                    section.data(226).dtTransOffset = 243;

                    ;% UAM_Flight_control_P.Saturation1_UpperSat_h
                    section.data(227).logicalSrcIdx = 397;
                    section.data(227).dtTransOffset = 244;

                    ;% UAM_Flight_control_P.Saturation1_LowerSat_i5
                    section.data(228).logicalSrcIdx = 398;
                    section.data(228).dtTransOffset = 245;

                    ;% UAM_Flight_control_P.Saturation2_UpperSat_e
                    section.data(229).logicalSrcIdx = 399;
                    section.data(229).dtTransOffset = 246;

                    ;% UAM_Flight_control_P.Saturation2_LowerSat_h
                    section.data(230).logicalSrcIdx = 400;
                    section.data(230).dtTransOffset = 247;

                    ;% UAM_Flight_control_P.Saturation3_UpperSat_b
                    section.data(231).logicalSrcIdx = 401;
                    section.data(231).dtTransOffset = 248;

                    ;% UAM_Flight_control_P.Saturation3_LowerSat_l
                    section.data(232).logicalSrcIdx = 402;
                    section.data(232).dtTransOffset = 249;

                    ;% UAM_Flight_control_P.MotorActuatorCommands_Y0_o
                    section.data(233).logicalSrcIdx = 403;
                    section.data(233).dtTransOffset = 250;

                    ;% UAM_Flight_control_P.Merge_1_InitialOutput
                    section.data(234).logicalSrcIdx = 404;
                    section.data(234).dtTransOffset = 251;

                    ;% UAM_Flight_control_P.Gain5_Gain_g
                    section.data(235).logicalSrcIdx = 405;
                    section.data(235).dtTransOffset = 252;

                    ;% UAM_Flight_control_P.Bias_Bias_c
                    section.data(236).logicalSrcIdx = 406;
                    section.data(236).dtTransOffset = 253;

                    ;% UAM_Flight_control_P.Saturation_UpperSat_j
                    section.data(237).logicalSrcIdx = 407;
                    section.data(237).dtTransOffset = 254;

                    ;% UAM_Flight_control_P.Saturation_LowerSat_a
                    section.data(238).logicalSrcIdx = 408;
                    section.data(238).dtTransOffset = 255;

                    ;% UAM_Flight_control_P.Merge_2_InitialOutput_o
                    section.data(239).logicalSrcIdx = 409;
                    section.data(239).dtTransOffset = 256;

                    ;% UAM_Flight_control_P.Gain6_Gain
                    section.data(240).logicalSrcIdx = 410;
                    section.data(240).dtTransOffset = 257;

                    ;% UAM_Flight_control_P.Bias1_Bias_a
                    section.data(241).logicalSrcIdx = 411;
                    section.data(241).dtTransOffset = 258;

                    ;% UAM_Flight_control_P.Saturation1_UpperSat_n
                    section.data(242).logicalSrcIdx = 412;
                    section.data(242).dtTransOffset = 259;

                    ;% UAM_Flight_control_P.Saturation1_LowerSat_ij
                    section.data(243).logicalSrcIdx = 413;
                    section.data(243).dtTransOffset = 260;

                    ;% UAM_Flight_control_P.Merge_3_InitialOutput_o
                    section.data(244).logicalSrcIdx = 414;
                    section.data(244).dtTransOffset = 261;

                    ;% UAM_Flight_control_P.Gain7_Gain_f
                    section.data(245).logicalSrcIdx = 415;
                    section.data(245).dtTransOffset = 262;

                    ;% UAM_Flight_control_P.Bias2_Bias
                    section.data(246).logicalSrcIdx = 416;
                    section.data(246).dtTransOffset = 263;

                    ;% UAM_Flight_control_P.Saturation2_UpperSat_d
                    section.data(247).logicalSrcIdx = 417;
                    section.data(247).dtTransOffset = 264;

                    ;% UAM_Flight_control_P.Saturation2_LowerSat_b3
                    section.data(248).logicalSrcIdx = 418;
                    section.data(248).dtTransOffset = 265;

                    ;% UAM_Flight_control_P.Merge_4_InitialOutput
                    section.data(249).logicalSrcIdx = 419;
                    section.data(249).dtTransOffset = 266;

                    ;% UAM_Flight_control_P.Gain8_Gain
                    section.data(250).logicalSrcIdx = 420;
                    section.data(250).dtTransOffset = 267;

                    ;% UAM_Flight_control_P.Bias3_Bias
                    section.data(251).logicalSrcIdx = 421;
                    section.data(251).dtTransOffset = 268;

                    ;% UAM_Flight_control_P.Saturation3_UpperSat_m
                    section.data(252).logicalSrcIdx = 422;
                    section.data(252).dtTransOffset = 269;

                    ;% UAM_Flight_control_P.Saturation3_LowerSat_i
                    section.data(253).logicalSrcIdx = 423;
                    section.data(253).dtTransOffset = 270;

                    ;% UAM_Flight_control_P.Merge_5_InitialOutput_o
                    section.data(254).logicalSrcIdx = 424;
                    section.data(254).dtTransOffset = 271;

                    ;% UAM_Flight_control_P.Gain9_Gain
                    section.data(255).logicalSrcIdx = 425;
                    section.data(255).dtTransOffset = 272;

                    ;% UAM_Flight_control_P.Bias4_Bias
                    section.data(256).logicalSrcIdx = 426;
                    section.data(256).dtTransOffset = 273;

                    ;% UAM_Flight_control_P.Saturation4_UpperSat_k
                    section.data(257).logicalSrcIdx = 427;
                    section.data(257).dtTransOffset = 274;

                    ;% UAM_Flight_control_P.Saturation4_LowerSat_o
                    section.data(258).logicalSrcIdx = 428;
                    section.data(258).dtTransOffset = 275;

                    ;% UAM_Flight_control_P.Constant_Value_a
                    section.data(259).logicalSrcIdx = 429;
                    section.data(259).dtTransOffset = 276;

                    ;% UAM_Flight_control_P.Constant_Value_f3
                    section.data(260).logicalSrcIdx = 430;
                    section.data(260).dtTransOffset = 277;

                    ;% UAM_Flight_control_P.Constant2_Value_im
                    section.data(261).logicalSrcIdx = 431;
                    section.data(261).dtTransOffset = 278;

                    ;% UAM_Flight_control_P.Constant3_Value_c
                    section.data(262).logicalSrcIdx = 432;
                    section.data(262).dtTransOffset = 279;

                    ;% UAM_Flight_control_P.Constant7_Value
                    section.data(263).logicalSrcIdx = 433;
                    section.data(263).dtTransOffset = 280;

                    ;% UAM_Flight_control_P.AER_Y0_e
                    section.data(264).logicalSrcIdx = 434;
                    section.data(264).dtTransOffset = 281;

                    ;% UAM_Flight_control_P.Constant1_Value_fa
                    section.data(265).logicalSrcIdx = 435;
                    section.data(265).dtTransOffset = 282;

                    ;% UAM_Flight_control_P.Clamping_zero_Value_bh
                    section.data(266).logicalSrcIdx = 436;
                    section.data(266).dtTransOffset = 283;

                    ;% UAM_Flight_control_P.Integrator_gainval_ap
                    section.data(267).logicalSrcIdx = 437;
                    section.data(267).dtTransOffset = 284;

                    ;% UAM_Flight_control_P.Filter_gainval_d
                    section.data(268).logicalSrcIdx = 438;
                    section.data(268).dtTransOffset = 285;

                    ;% UAM_Flight_control_P.Saturation2_UpperSat_a
                    section.data(269).logicalSrcIdx = 439;
                    section.data(269).dtTransOffset = 286;

                    ;% UAM_Flight_control_P.Saturation2_LowerSat_i2
                    section.data(270).logicalSrcIdx = 440;
                    section.data(270).dtTransOffset = 287;

                    ;% UAM_Flight_control_P.Bias_Bias_b
                    section.data(271).logicalSrcIdx = 441;
                    section.data(271).dtTransOffset = 288;

                    ;% UAM_Flight_control_P.Gain_Gain_a
                    section.data(272).logicalSrcIdx = 442;
                    section.data(272).dtTransOffset = 289;

                    ;% UAM_Flight_control_P.Gain1_Gain_dd
                    section.data(273).logicalSrcIdx = 443;
                    section.data(273).dtTransOffset = 290;

                    ;% UAM_Flight_control_P.Bias_Bias_g
                    section.data(274).logicalSrcIdx = 444;
                    section.data(274).dtTransOffset = 291;

                    ;% UAM_Flight_control_P.Gain_Gain_m
                    section.data(275).logicalSrcIdx = 445;
                    section.data(275).dtTransOffset = 292;

                    ;% UAM_Flight_control_P.Gain1_Gain_h
                    section.data(276).logicalSrcIdx = 446;
                    section.data(276).dtTransOffset = 293;

                    ;% UAM_Flight_control_P.Saturation1_UpperSat_i
                    section.data(277).logicalSrcIdx = 447;
                    section.data(277).dtTransOffset = 294;

                    ;% UAM_Flight_control_P.Saturation1_LowerSat_g
                    section.data(278).logicalSrcIdx = 448;
                    section.data(278).dtTransOffset = 295;

                    ;% UAM_Flight_control_P.Saturation5_UpperSat_c
                    section.data(279).logicalSrcIdx = 449;
                    section.data(279).dtTransOffset = 296;

                    ;% UAM_Flight_control_P.Saturation5_LowerSat_b
                    section.data(280).logicalSrcIdx = 450;
                    section.data(280).dtTransOffset = 297;

                    ;% UAM_Flight_control_P.Saturation2_UpperSat_f
                    section.data(281).logicalSrcIdx = 451;
                    section.data(281).dtTransOffset = 298;

                    ;% UAM_Flight_control_P.Saturation2_LowerSat_j
                    section.data(282).logicalSrcIdx = 452;
                    section.data(282).dtTransOffset = 299;

                    ;% UAM_Flight_control_P.Saturation6_UpperSat_i
                    section.data(283).logicalSrcIdx = 453;
                    section.data(283).dtTransOffset = 300;

                    ;% UAM_Flight_control_P.Saturation6_LowerSat_o
                    section.data(284).logicalSrcIdx = 454;
                    section.data(284).dtTransOffset = 301;

                    ;% UAM_Flight_control_P.Saturation3_UpperSat_i
                    section.data(285).logicalSrcIdx = 455;
                    section.data(285).dtTransOffset = 302;

                    ;% UAM_Flight_control_P.Saturation3_LowerSat_c
                    section.data(286).logicalSrcIdx = 456;
                    section.data(286).dtTransOffset = 303;

                    ;% UAM_Flight_control_P.Saturation7_UpperSat_j
                    section.data(287).logicalSrcIdx = 457;
                    section.data(287).dtTransOffset = 304;

                    ;% UAM_Flight_control_P.Saturation7_LowerSat_g
                    section.data(288).logicalSrcIdx = 458;
                    section.data(288).dtTransOffset = 305;

                    ;% UAM_Flight_control_P.Constant4_Value_il
                    section.data(289).logicalSrcIdx = 459;
                    section.data(289).dtTransOffset = 306;

                    ;% UAM_Flight_control_P.Saturation_UpperSat_h
                    section.data(290).logicalSrcIdx = 460;
                    section.data(290).dtTransOffset = 307;

                    ;% UAM_Flight_control_P.Saturation_LowerSat_i
                    section.data(291).logicalSrcIdx = 461;
                    section.data(291).dtTransOffset = 308;

                    ;% UAM_Flight_control_P.Saturation4_UpperSat_d
                    section.data(292).logicalSrcIdx = 462;
                    section.data(292).dtTransOffset = 309;

                    ;% UAM_Flight_control_P.Saturation4_LowerSat_gy
                    section.data(293).logicalSrcIdx = 463;
                    section.data(293).dtTransOffset = 310;

                    ;% UAM_Flight_control_P.Constant9_Value
                    section.data(294).logicalSrcIdx = 464;
                    section.data(294).dtTransOffset = 311;

                    ;% UAM_Flight_control_P.Constant10_Value
                    section.data(295).logicalSrcIdx = 465;
                    section.data(295).dtTransOffset = 312;

                    ;% UAM_Flight_control_P.Constant11_Value
                    section.data(296).logicalSrcIdx = 466;
                    section.data(296).dtTransOffset = 313;

                    ;% UAM_Flight_control_P.Constant8_Value_i
                    section.data(297).logicalSrcIdx = 467;
                    section.data(297).dtTransOffset = 314;

                    ;% UAM_Flight_control_P.Constant6_Value_n
                    section.data(298).logicalSrcIdx = 468;
                    section.data(298).dtTransOffset = 315;

                    ;% UAM_Flight_control_P.MotorActuatorCommands_Y0_j
                    section.data(299).logicalSrcIdx = 469;
                    section.data(299).dtTransOffset = 316;

                    ;% UAM_Flight_control_P.Merge_1_InitialOutput_f
                    section.data(300).logicalSrcIdx = 470;
                    section.data(300).dtTransOffset = 317;

                    ;% UAM_Flight_control_P.Gain5_Gain_ga
                    section.data(301).logicalSrcIdx = 471;
                    section.data(301).dtTransOffset = 318;

                    ;% UAM_Flight_control_P.Bias_Bias_be
                    section.data(302).logicalSrcIdx = 472;
                    section.data(302).dtTransOffset = 319;

                    ;% UAM_Flight_control_P.Merge_2_InitialOutput_f
                    section.data(303).logicalSrcIdx = 473;
                    section.data(303).dtTransOffset = 320;

                    ;% UAM_Flight_control_P.Gain6_Gain_e
                    section.data(304).logicalSrcIdx = 474;
                    section.data(304).dtTransOffset = 321;

                    ;% UAM_Flight_control_P.Bias1_Bias_p
                    section.data(305).logicalSrcIdx = 475;
                    section.data(305).dtTransOffset = 322;

                    ;% UAM_Flight_control_P.Merge_3_InitialOutput_f
                    section.data(306).logicalSrcIdx = 476;
                    section.data(306).dtTransOffset = 323;

                    ;% UAM_Flight_control_P.Gain7_Gain_c
                    section.data(307).logicalSrcIdx = 477;
                    section.data(307).dtTransOffset = 324;

                    ;% UAM_Flight_control_P.Bias2_Bias_j
                    section.data(308).logicalSrcIdx = 478;
                    section.data(308).dtTransOffset = 325;

                    ;% UAM_Flight_control_P.Merge_4_InitialOutput_f
                    section.data(309).logicalSrcIdx = 479;
                    section.data(309).dtTransOffset = 326;

                    ;% UAM_Flight_control_P.Gain8_Gain_j
                    section.data(310).logicalSrcIdx = 480;
                    section.data(310).dtTransOffset = 327;

                    ;% UAM_Flight_control_P.Bias3_Bias_i
                    section.data(311).logicalSrcIdx = 481;
                    section.data(311).dtTransOffset = 328;

                    ;% UAM_Flight_control_P.Merge_5_InitialOutput_f
                    section.data(312).logicalSrcIdx = 482;
                    section.data(312).dtTransOffset = 329;

                    ;% UAM_Flight_control_P.Gain9_Gain_c
                    section.data(313).logicalSrcIdx = 483;
                    section.data(313).dtTransOffset = 330;

                    ;% UAM_Flight_control_P.Bias4_Bias_b
                    section.data(314).logicalSrcIdx = 484;
                    section.data(314).dtTransOffset = 331;

                    ;% UAM_Flight_control_P.Constant_Value_obg
                    section.data(315).logicalSrcIdx = 485;
                    section.data(315).dtTransOffset = 332;

                    ;% UAM_Flight_control_P.Saturation_UpperSat_b
                    section.data(316).logicalSrcIdx = 486;
                    section.data(316).dtTransOffset = 333;

                    ;% UAM_Flight_control_P.Saturation_LowerSat_d3
                    section.data(317).logicalSrcIdx = 487;
                    section.data(317).dtTransOffset = 334;

                    ;% UAM_Flight_control_P.Saturation1_UpperSat_c
                    section.data(318).logicalSrcIdx = 488;
                    section.data(318).dtTransOffset = 335;

                    ;% UAM_Flight_control_P.Saturation1_LowerSat_bx
                    section.data(319).logicalSrcIdx = 489;
                    section.data(319).dtTransOffset = 336;

                    ;% UAM_Flight_control_P.Saturation2_UpperSat_bs
                    section.data(320).logicalSrcIdx = 490;
                    section.data(320).dtTransOffset = 337;

                    ;% UAM_Flight_control_P.Saturation2_LowerSat_h3
                    section.data(321).logicalSrcIdx = 491;
                    section.data(321).dtTransOffset = 338;

                    ;% UAM_Flight_control_P.Saturation3_UpperSat_f
                    section.data(322).logicalSrcIdx = 492;
                    section.data(322).dtTransOffset = 339;

                    ;% UAM_Flight_control_P.Saturation3_LowerSat_j
                    section.data(323).logicalSrcIdx = 493;
                    section.data(323).dtTransOffset = 340;

                    ;% UAM_Flight_control_P.Saturation4_UpperSat_bt
                    section.data(324).logicalSrcIdx = 494;
                    section.data(324).dtTransOffset = 341;

                    ;% UAM_Flight_control_P.Saturation4_LowerSat_c
                    section.data(325).logicalSrcIdx = 495;
                    section.data(325).dtTransOffset = 342;

                    ;% UAM_Flight_control_P.Bias_Bias_a
                    section.data(326).logicalSrcIdx = 496;
                    section.data(326).dtTransOffset = 343;

                    ;% UAM_Flight_control_P.Gain_Gain_b4
                    section.data(327).logicalSrcIdx = 497;
                    section.data(327).dtTransOffset = 344;

                    ;% UAM_Flight_control_P.Filter_gainval_h
                    section.data(328).logicalSrcIdx = 498;
                    section.data(328).dtTransOffset = 345;

                    ;% UAM_Flight_control_P.Bias_Bias_d
                    section.data(329).logicalSrcIdx = 499;
                    section.data(329).dtTransOffset = 346;

                    ;% UAM_Flight_control_P.Gain_Gain_d3
                    section.data(330).logicalSrcIdx = 500;
                    section.data(330).dtTransOffset = 347;

                    ;% UAM_Flight_control_P.Saturation_UpperSat_ja
                    section.data(331).logicalSrcIdx = 501;
                    section.data(331).dtTransOffset = 348;

                    ;% UAM_Flight_control_P.Saturation_LowerSat_bu
                    section.data(332).logicalSrcIdx = 502;
                    section.data(332).dtTransOffset = 349;

                    ;% UAM_Flight_control_P.UnitDelay_1_InitialCondition
                    section.data(333).logicalSrcIdx = 503;
                    section.data(333).dtTransOffset = 350;

                    ;% UAM_Flight_control_P.UnitDelay_2_InitialCondition_g
                    section.data(334).logicalSrcIdx = 504;
                    section.data(334).dtTransOffset = 351;

                    ;% UAM_Flight_control_P.UnitDelay_3_InitialCondition_g
                    section.data(335).logicalSrcIdx = 505;
                    section.data(335).dtTransOffset = 352;

                    ;% UAM_Flight_control_P.UnitDelay_4_InitialCondition
                    section.data(336).logicalSrcIdx = 506;
                    section.data(336).dtTransOffset = 353;

                    ;% UAM_Flight_control_P.Gain_Gain_dm
                    section.data(337).logicalSrcIdx = 507;
                    section.data(337).dtTransOffset = 354;

                    ;% UAM_Flight_control_P.Constant1_Value_i
                    section.data(338).logicalSrcIdx = 508;
                    section.data(338).dtTransOffset = 355;

                    ;% UAM_Flight_control_P.Constant2_Value_iv
                    section.data(339).logicalSrcIdx = 509;
                    section.data(339).dtTransOffset = 356;

                    ;% UAM_Flight_control_P.Constant_Value_b
                    section.data(340).logicalSrcIdx = 510;
                    section.data(340).dtTransOffset = 357;

                    ;% UAM_Flight_control_P.Constant1_Value_n
                    section.data(341).logicalSrcIdx = 511;
                    section.data(341).dtTransOffset = 358;

                    ;% UAM_Flight_control_P.Constant1_Value_d
                    section.data(342).logicalSrcIdx = 512;
                    section.data(342).dtTransOffset = 359;

                    ;% UAM_Flight_control_P.Constant3_Value_n
                    section.data(343).logicalSrcIdx = 513;
                    section.data(343).dtTransOffset = 360;

                    ;% UAM_Flight_control_P.Constant1_Value_ii
                    section.data(344).logicalSrcIdx = 514;
                    section.data(344).dtTransOffset = 363;

                    ;% UAM_Flight_control_P.Constant2_Value_h
                    section.data(345).logicalSrcIdx = 515;
                    section.data(345).dtTransOffset = 364;

                    ;% UAM_Flight_control_P.Constant_Value_h
                    section.data(346).logicalSrcIdx = 516;
                    section.data(346).dtTransOffset = 365;

                    ;% UAM_Flight_control_P.Constant_Value_l
                    section.data(347).logicalSrcIdx = 517;
                    section.data(347).dtTransOffset = 366;

                    ;% UAM_Flight_control_P.HdgCmdSat_UpperSat
                    section.data(348).logicalSrcIdx = 518;
                    section.data(348).dtTransOffset = 367;

                    ;% UAM_Flight_control_P.HdgCmdSat_LowerSat
                    section.data(349).logicalSrcIdx = 519;
                    section.data(349).dtTransOffset = 368;

                    ;% UAM_Flight_control_P.YawCmdSat_UpperSat
                    section.data(350).logicalSrcIdx = 520;
                    section.data(350).dtTransOffset = 369;

                    ;% UAM_Flight_control_P.YawCmdSat_LowerSat
                    section.data(351).logicalSrcIdx = 521;
                    section.data(351).dtTransOffset = 370;

                    ;% UAM_Flight_control_P.LookaheadDistance_Value
                    section.data(352).logicalSrcIdx = 522;
                    section.data(352).dtTransOffset = 371;

                    ;% UAM_Flight_control_P.LookaheadDistance_Value_i
                    section.data(353).logicalSrcIdx = 523;
                    section.data(353).dtTransOffset = 372;

                    ;% UAM_Flight_control_P.HdgCmdSat_UpperSat_g
                    section.data(354).logicalSrcIdx = 524;
                    section.data(354).dtTransOffset = 373;

                    ;% UAM_Flight_control_P.HdgCmdSat_LowerSat_c
                    section.data(355).logicalSrcIdx = 525;
                    section.data(355).dtTransOffset = 374;

                    ;% UAM_Flight_control_P.Constant1_Value_fp
                    section.data(356).logicalSrcIdx = 526;
                    section.data(356).dtTransOffset = 375;

                    ;% UAM_Flight_control_P.YawCmdSat_UpperSat_h
                    section.data(357).logicalSrcIdx = 527;
                    section.data(357).dtTransOffset = 376;

                    ;% UAM_Flight_control_P.YawCmdSat_LowerSat_c
                    section.data(358).logicalSrcIdx = 528;
                    section.data(358).dtTransOffset = 377;

                    ;% UAM_Flight_control_P.HoldPositionValue_Y0
                    section.data(359).logicalSrcIdx = 529;
                    section.data(359).dtTransOffset = 378;

                    ;% UAM_Flight_control_P.Constant_Value_bt
                    section.data(360).logicalSrcIdx = 530;
                    section.data(360).dtTransOffset = 379;

                    ;% UAM_Flight_control_P.LookaheadDistance_Value_k
                    section.data(361).logicalSrcIdx = 531;
                    section.data(361).dtTransOffset = 380;

                    ;% UAM_Flight_control_P.YawCmdSat_UpperSat_a
                    section.data(362).logicalSrcIdx = 532;
                    section.data(362).dtTransOffset = 381;

                    ;% UAM_Flight_control_P.YawCmdSat_LowerSat_k
                    section.data(363).logicalSrcIdx = 533;
                    section.data(363).dtTransOffset = 382;

                    ;% UAM_Flight_control_P.Saturation_UpperSat_k
                    section.data(364).logicalSrcIdx = 534;
                    section.data(364).dtTransOffset = 383;

                    ;% UAM_Flight_control_P.Saturation_LowerSat_l
                    section.data(365).logicalSrcIdx = 535;
                    section.data(365).dtTransOffset = 384;

                    ;% UAM_Flight_control_P.Constant1_Value_gn
                    section.data(366).logicalSrcIdx = 536;
                    section.data(366).dtTransOffset = 385;

                    ;% UAM_Flight_control_P.UnitDelay_1_InitialCondition_l
                    section.data(367).logicalSrcIdx = 537;
                    section.data(367).dtTransOffset = 386;

                    ;% UAM_Flight_control_P.UnitDelay_2_InitialCondition_l
                    section.data(368).logicalSrcIdx = 538;
                    section.data(368).dtTransOffset = 387;

                    ;% UAM_Flight_control_P.UnitDelay_3_InitialCondition_l
                    section.data(369).logicalSrcIdx = 539;
                    section.data(369).dtTransOffset = 388;

                    ;% UAM_Flight_control_P.UnitDelay_4_InitialCondition_l
                    section.data(370).logicalSrcIdx = 540;
                    section.data(370).dtTransOffset = 389;

                    ;% UAM_Flight_control_P.UnitDelay_1_InitialCondition_lw
                    section.data(371).logicalSrcIdx = 541;
                    section.data(371).dtTransOffset = 390;

                    ;% UAM_Flight_control_P.Constant_Value_fa
                    section.data(372).logicalSrcIdx = 542;
                    section.data(372).dtTransOffset = 391;

                    ;% UAM_Flight_control_P.UnitDelay_2_InitialCondition_lw
                    section.data(373).logicalSrcIdx = 543;
                    section.data(373).dtTransOffset = 392;

                    ;% UAM_Flight_control_P.Constant4_Value_k
                    section.data(374).logicalSrcIdx = 544;
                    section.data(374).dtTransOffset = 393;

                    ;% UAM_Flight_control_P.UnitDelay_3_InitialCondition_lw
                    section.data(375).logicalSrcIdx = 545;
                    section.data(375).dtTransOffset = 394;

                    ;% UAM_Flight_control_P.Constant5_Value_d
                    section.data(376).logicalSrcIdx = 546;
                    section.data(376).dtTransOffset = 395;

                    ;% UAM_Flight_control_P.UnitDelay_4_InitialCondition_lw
                    section.data(377).logicalSrcIdx = 547;
                    section.data(377).dtTransOffset = 396;

                    ;% UAM_Flight_control_P.Constant6_Value_a
                    section.data(378).logicalSrcIdx = 548;
                    section.data(378).dtTransOffset = 397;

                    ;% UAM_Flight_control_P.Constant3_Value_o
                    section.data(379).logicalSrcIdx = 549;
                    section.data(379).dtTransOffset = 398;

                    ;% UAM_Flight_control_P.Constant1_Value_k
                    section.data(380).logicalSrcIdx = 550;
                    section.data(380).dtTransOffset = 402;

                    ;% UAM_Flight_control_P.AHRS_AccelerometerNoise
                    section.data(381).logicalSrcIdx = 551;
                    section.data(381).dtTransOffset = 405;

                    ;% UAM_Flight_control_P.AHRS_GyroscopeNoise
                    section.data(382).logicalSrcIdx = 552;
                    section.data(382).dtTransOffset = 406;

                    ;% UAM_Flight_control_P.AHRS_MagnetometerNoise
                    section.data(383).logicalSrcIdx = 553;
                    section.data(383).dtTransOffset = 407;

                    ;% UAM_Flight_control_P.AHRS_GyroscopeDriftNoise
                    section.data(384).logicalSrcIdx = 554;
                    section.data(384).dtTransOffset = 408;

                    ;% UAM_Flight_control_P.AHRS_LinearAccelerationNoise
                    section.data(385).logicalSrcIdx = 555;
                    section.data(385).dtTransOffset = 409;

                    ;% UAM_Flight_control_P.AHRS_MagneticDisturbanceNoise
                    section.data(386).logicalSrcIdx = 556;
                    section.data(386).dtTransOffset = 410;

                    ;% UAM_Flight_control_P.AHRS_LinearAccelerationDecayFac
                    section.data(387).logicalSrcIdx = 557;
                    section.data(387).dtTransOffset = 411;

                    ;% UAM_Flight_control_P.AHRS_MagneticDisturbanceDecayFa
                    section.data(388).logicalSrcIdx = 558;
                    section.data(388).dtTransOffset = 412;

                    ;% UAM_Flight_control_P.AHRS_ExpectedMagneticFieldStren
                    section.data(389).logicalSrcIdx = 559;
                    section.data(389).dtTransOffset = 413;

                    ;% UAM_Flight_control_P.Constant5_Value_h
                    section.data(390).logicalSrcIdx = 560;
                    section.data(390).dtTransOffset = 414;

                    ;% UAM_Flight_control_P.Constant_Value_gj
                    section.data(391).logicalSrcIdx = 561;
                    section.data(391).dtTransOffset = 415;

                    ;% UAM_Flight_control_P.Constant_Value_hz
                    section.data(392).logicalSrcIdx = 562;
                    section.data(392).dtTransOffset = 418;

                    ;% UAM_Flight_control_P.Gain1_Gain_db
                    section.data(393).logicalSrcIdx = 563;
                    section.data(393).dtTransOffset = 419;

                    ;% UAM_Flight_control_P.Constant_Value_j
                    section.data(394).logicalSrcIdx = 564;
                    section.data(394).dtTransOffset = 420;

                    ;% UAM_Flight_control_P.Gain1_Gain_n
                    section.data(395).logicalSrcIdx = 565;
                    section.data(395).dtTransOffset = 421;

                    ;% UAM_Flight_control_P.UnitDelay2_InitialCondition
                    section.data(396).logicalSrcIdx = 566;
                    section.data(396).dtTransOffset = 422;

                    ;% UAM_Flight_control_P.UnitDelay3_InitialCondition
                    section.data(397).logicalSrcIdx = 567;
                    section.data(397).dtTransOffset = 423;

                    ;% UAM_Flight_control_P.UnitDelay4_InitialCondition
                    section.data(398).logicalSrcIdx = 568;
                    section.data(398).dtTransOffset = 424;

                    ;% UAM_Flight_control_P.Ts_Value
                    section.data(399).logicalSrcIdx = 569;
                    section.data(399).dtTransOffset = 425;

                    ;% UAM_Flight_control_P.Constant1_Value_fay
                    section.data(400).logicalSrcIdx = 570;
                    section.data(400).dtTransOffset = 426;

                    ;% UAM_Flight_control_P.Constant2_Value_c
                    section.data(401).logicalSrcIdx = 571;
                    section.data(401).dtTransOffset = 427;

                    ;% UAM_Flight_control_P.Constant4_Value_g
                    section.data(402).logicalSrcIdx = 572;
                    section.data(402).dtTransOffset = 428;

                    ;% UAM_Flight_control_P.R_baro_Value
                    section.data(403).logicalSrcIdx = 573;
                    section.data(403).dtTransOffset = 429;

                    ;% UAM_Flight_control_P.R_vgps_Value
                    section.data(404).logicalSrcIdx = 574;
                    section.data(404).dtTransOffset = 430;

                    ;% UAM_Flight_control_P.Rgps_Value
                    section.data(405).logicalSrcIdx = 575;
                    section.data(405).dtTransOffset = 431;

                    ;% UAM_Flight_control_P.UnitDelay5_InitialCondition
                    section.data(406).logicalSrcIdx = 576;
                    section.data(406).dtTransOffset = 432;

                    ;% UAM_Flight_control_P.Gain2_Gain_k
                    section.data(407).logicalSrcIdx = 577;
                    section.data(407).dtTransOffset = 433;

                    ;% UAM_Flight_control_P.UnitDelay1_InitialCondition_j
                    section.data(408).logicalSrcIdx = 578;
                    section.data(408).dtTransOffset = 434;

                    ;% UAM_Flight_control_P.UnitDelay_InitialCondition_b
                    section.data(409).logicalSrcIdx = 579;
                    section.data(409).dtTransOffset = 435;

                    ;% UAM_Flight_control_P.dt1_Gain
                    section.data(410).logicalSrcIdx = 580;
                    section.data(410).dtTransOffset = 436;

                    ;% UAM_Flight_control_P.UnitDelay_InitialCondition_f
                    section.data(411).logicalSrcIdx = 581;
                    section.data(411).dtTransOffset = 437;

                    ;% UAM_Flight_control_P.Gyro_bias_Value
                    section.data(412).logicalSrcIdx = 582;
                    section.data(412).dtTransOffset = 441;

                    ;% UAM_Flight_control_P.Gain2_Gain_e
                    section.data(413).logicalSrcIdx = 583;
                    section.data(413).dtTransOffset = 444;

                    ;% UAM_Flight_control_P.dt_Gain
                    section.data(414).logicalSrcIdx = 584;
                    section.data(414).dtTransOffset = 445;

                    ;% UAM_Flight_control_P.bias_Value
                    section.data(415).logicalSrcIdx = 585;
                    section.data(415).dtTransOffset = 446;

                    ;% UAM_Flight_control_P.g_Value
                    section.data(416).logicalSrcIdx = 586;
                    section.data(416).dtTransOffset = 449;

                    ;% UAM_Flight_control_P.u5dt2_Gain
                    section.data(417).logicalSrcIdx = 587;
                    section.data(417).dtTransOffset = 450;

                    ;% UAM_Flight_control_P.dt_Gain_g
                    section.data(418).logicalSrcIdx = 588;
                    section.data(418).dtTransOffset = 451;

                    ;% UAM_Flight_control_P.Gain_Gain_iq
                    section.data(419).logicalSrcIdx = 589;
                    section.data(419).dtTransOffset = 452;

                    ;% UAM_Flight_control_P.UnitDelay1_9_InitialCondition
                    section.data(420).logicalSrcIdx = 590;
                    section.data(420).dtTransOffset = 453;

                    ;% UAM_Flight_control_P.UnitDelay1_8_InitialCondition
                    section.data(421).logicalSrcIdx = 591;
                    section.data(421).dtTransOffset = 454;

                    ;% UAM_Flight_control_P.UnitDelay1_6_InitialCondition
                    section.data(422).logicalSrcIdx = 592;
                    section.data(422).dtTransOffset = 455;

                    ;% UAM_Flight_control_P.UnitDelay1_5_InitialCondition
                    section.data(423).logicalSrcIdx = 593;
                    section.data(423).dtTransOffset = 456;

                    ;% UAM_Flight_control_P.UnitDelay1_4_InitialCondition
                    section.data(424).logicalSrcIdx = 594;
                    section.data(424).dtTransOffset = 457;

                    ;% UAM_Flight_control_P.UnitDelay1_3_InitialCondition
                    section.data(425).logicalSrcIdx = 595;
                    section.data(425).dtTransOffset = 458;

                    ;% UAM_Flight_control_P.UnitDelay1_2_InitialCondition
                    section.data(426).logicalSrcIdx = 596;
                    section.data(426).dtTransOffset = 459;

                    ;% UAM_Flight_control_P.UnitDelay1_1_InitialCondition
                    section.data(427).logicalSrcIdx = 597;
                    section.data(427).dtTransOffset = 460;

                    ;% UAM_Flight_control_P.UnitDelay2_InitialCondition_g
                    section.data(428).logicalSrcIdx = 598;
                    section.data(428).dtTransOffset = 461;

                    ;% UAM_Flight_control_P.UnitDelay1_10_InitialCondition
                    section.data(429).logicalSrcIdx = 599;
                    section.data(429).dtTransOffset = 462;

                    ;% UAM_Flight_control_P.Merge_1_InitialOutput_g
                    section.data(430).logicalSrcIdx = 600;
                    section.data(430).dtTransOffset = 463;

                    ;% UAM_Flight_control_P.Merge_2_InitialOutput_g
                    section.data(431).logicalSrcIdx = 601;
                    section.data(431).dtTransOffset = 464;

                    ;% UAM_Flight_control_P.Merge_3_InitialOutput_g
                    section.data(432).logicalSrcIdx = 602;
                    section.data(432).dtTransOffset = 465;

                    ;% UAM_Flight_control_P.Merge_4_InitialOutput_g
                    section.data(433).logicalSrcIdx = 603;
                    section.data(433).dtTransOffset = 466;

                    ;% UAM_Flight_control_P.Merge_1_InitialOutput_e
                    section.data(434).logicalSrcIdx = 604;
                    section.data(434).dtTransOffset = 467;

                    ;% UAM_Flight_control_P.Merge_2_InitialOutput_e
                    section.data(435).logicalSrcIdx = 605;
                    section.data(435).dtTransOffset = 468;

                    ;% UAM_Flight_control_P.Merge_3_InitialOutput_e
                    section.data(436).logicalSrcIdx = 606;
                    section.data(436).dtTransOffset = 469;

                    ;% UAM_Flight_control_P.Merge_4_InitialOutput_e
                    section.data(437).logicalSrcIdx = 607;
                    section.data(437).dtTransOffset = 470;

                    ;% UAM_Flight_control_P.Merge_9_InitialOutput
                    section.data(438).logicalSrcIdx = 608;
                    section.data(438).dtTransOffset = 471;

                    ;% UAM_Flight_control_P.Merge_10_InitialOutput_e
                    section.data(439).logicalSrcIdx = 609;
                    section.data(439).dtTransOffset = 472;

                    ;% UAM_Flight_control_P.Merge_18_InitialOutput
                    section.data(440).logicalSrcIdx = 610;
                    section.data(440).dtTransOffset = 473;

                    ;% UAM_Flight_control_P.Merge_19_InitialOutput
                    section.data(441).logicalSrcIdx = 611;
                    section.data(441).dtTransOffset = 474;

                    ;% UAM_Flight_control_P.Merge_20_InitialOutput
                    section.data(442).logicalSrcIdx = 612;
                    section.data(442).dtTransOffset = 475;

                    ;% UAM_Flight_control_P.Merge_21_InitialOutput
                    section.data(443).logicalSrcIdx = 613;
                    section.data(443).dtTransOffset = 476;

                    ;% UAM_Flight_control_P.Merge_22_InitialOutput
                    section.data(444).logicalSrcIdx = 614;
                    section.data(444).dtTransOffset = 477;

                    ;% UAM_Flight_control_P.Merge_23_InitialOutput
                    section.data(445).logicalSrcIdx = 615;
                    section.data(445).dtTransOffset = 478;

                    ;% UAM_Flight_control_P.Merge_24_InitialOutput
                    section.data(446).logicalSrcIdx = 616;
                    section.data(446).dtTransOffset = 479;

                    ;% UAM_Flight_control_P.Merge_25_InitialOutput
                    section.data(447).logicalSrcIdx = 617;
                    section.data(447).dtTransOffset = 480;

                    ;% UAM_Flight_control_P.Merge_29_InitialOutput
                    section.data(448).logicalSrcIdx = 618;
                    section.data(448).dtTransOffset = 481;

                    ;% UAM_Flight_control_P.Merge_30_InitialOutput
                    section.data(449).logicalSrcIdx = 619;
                    section.data(449).dtTransOffset = 482;

                    ;% UAM_Flight_control_P.Merge_31_InitialOutput
                    section.data(450).logicalSrcIdx = 620;
                    section.data(450).dtTransOffset = 483;

                    ;% UAM_Flight_control_P.Merge_32_InitialOutput
                    section.data(451).logicalSrcIdx = 621;
                    section.data(451).dtTransOffset = 484;

                    ;% UAM_Flight_control_P.Merge_33_InitialOutput
                    section.data(452).logicalSrcIdx = 622;
                    section.data(452).dtTransOffset = 485;

                    ;% UAM_Flight_control_P.Merge_34_InitialOutput
                    section.data(453).logicalSrcIdx = 623;
                    section.data(453).dtTransOffset = 486;

                    ;% UAM_Flight_control_P.Merge_35_InitialOutput
                    section.data(454).logicalSrcIdx = 624;
                    section.data(454).dtTransOffset = 487;

                    ;% UAM_Flight_control_P.Merge_36_InitialOutput
                    section.data(455).logicalSrcIdx = 625;
                    section.data(455).dtTransOffset = 488;

                    ;% UAM_Flight_control_P.Merge_37_InitialOutput
                    section.data(456).logicalSrcIdx = 626;
                    section.data(456).dtTransOffset = 489;

                    ;% UAM_Flight_control_P.Merge_38_InitialOutput
                    section.data(457).logicalSrcIdx = 627;
                    section.data(457).dtTransOffset = 490;

                    ;% UAM_Flight_control_P.Merge_39_InitialOutput
                    section.data(458).logicalSrcIdx = 628;
                    section.data(458).dtTransOffset = 491;

                    ;% UAM_Flight_control_P.Merge_48_InitialOutput
                    section.data(459).logicalSrcIdx = 629;
                    section.data(459).dtTransOffset = 492;

                    ;% UAM_Flight_control_P.Merge_49_InitialOutput
                    section.data(460).logicalSrcIdx = 630;
                    section.data(460).dtTransOffset = 493;

                    ;% UAM_Flight_control_P.Merge_50_InitialOutput
                    section.data(461).logicalSrcIdx = 631;
                    section.data(461).dtTransOffset = 494;

                    ;% UAM_Flight_control_P.dt2_Value
                    section.data(462).logicalSrcIdx = 632;
                    section.data(462).dtTransOffset = 495;

                    ;% UAM_Flight_control_P.Merge_51_InitialOutput
                    section.data(463).logicalSrcIdx = 633;
                    section.data(463).dtTransOffset = 496;

                    ;% UAM_Flight_control_P.Merge_53_InitialOutput
                    section.data(464).logicalSrcIdx = 634;
                    section.data(464).dtTransOffset = 497;

                    ;% UAM_Flight_control_P.ground_Value
                    section.data(465).logicalSrcIdx = 635;
                    section.data(465).dtTransOffset = 498;

                    ;% UAM_Flight_control_P.Merge_11_InitialOutput
                    section.data(466).logicalSrcIdx = 636;
                    section.data(466).dtTransOffset = 499;

                    ;% UAM_Flight_control_P.Merge_12_InitialOutput
                    section.data(467).logicalSrcIdx = 637;
                    section.data(467).dtTransOffset = 500;

                    ;% UAM_Flight_control_P.Merge_13_InitialOutput
                    section.data(468).logicalSrcIdx = 638;
                    section.data(468).dtTransOffset = 501;

                    ;% UAM_Flight_control_P.Merge_4_InitialOutput_l
                    section.data(469).logicalSrcIdx = 639;
                    section.data(469).dtTransOffset = 502;

                    ;% UAM_Flight_control_P.Merge_5_InitialOutput_l
                    section.data(470).logicalSrcIdx = 640;
                    section.data(470).dtTransOffset = 503;

                    ;% UAM_Flight_control_P.Merge_6_InitialOutput_l
                    section.data(471).logicalSrcIdx = 641;
                    section.data(471).dtTransOffset = 504;

                    ;% UAM_Flight_control_P.Merge_7_InitialOutput_l
                    section.data(472).logicalSrcIdx = 642;
                    section.data(472).dtTransOffset = 505;

                    ;% UAM_Flight_control_P.Merge_8_InitialOutput
                    section.data(473).logicalSrcIdx = 643;
                    section.data(473).dtTransOffset = 506;

                    ;% UAM_Flight_control_P.Merge_9_InitialOutput_l
                    section.data(474).logicalSrcIdx = 644;
                    section.data(474).dtTransOffset = 507;

                    ;% UAM_Flight_control_P.Gain_Gain_n
                    section.data(475).logicalSrcIdx = 645;
                    section.data(475).dtTransOffset = 508;

                    ;% UAM_Flight_control_P.Gain1_Gain_l
                    section.data(476).logicalSrcIdx = 646;
                    section.data(476).dtTransOffset = 509;

                    ;% UAM_Flight_control_P.Constant1_Value_gm
                    section.data(477).logicalSrcIdx = 647;
                    section.data(477).dtTransOffset = 510;

                    ;% UAM_Flight_control_P.Constant7_Value_o
                    section.data(478).logicalSrcIdx = 648;
                    section.data(478).dtTransOffset = 511;

            nTotData = nTotData + section.nData;
            paramMap.sections(49) = section;
            clear section

            section.nData     = 10;
            section.data(10)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Constant_Value_ne
                    section.data(1).logicalSrcIdx = 649;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_P.Constant1_Value_k2
                    section.data(2).logicalSrcIdx = 650;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_P.Constant4_Value_de
                    section.data(3).logicalSrcIdx = 651;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_P.Constant_Value_ld
                    section.data(4).logicalSrcIdx = 652;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_P.Constant_Value_i
                    section.data(5).logicalSrcIdx = 653;
                    section.data(5).dtTransOffset = 4;

                    ;% UAM_Flight_control_P.Constant1_Value_gz
                    section.data(6).logicalSrcIdx = 654;
                    section.data(6).dtTransOffset = 5;

                    ;% UAM_Flight_control_P.UnitDelay_8_InitialCondition
                    section.data(7).logicalSrcIdx = 655;
                    section.data(7).dtTransOffset = 6;

                    ;% UAM_Flight_control_P.UnitDelay_8_InitialCondition_l
                    section.data(8).logicalSrcIdx = 656;
                    section.data(8).dtTransOffset = 7;

                    ;% UAM_Flight_control_P.UnitDelay_8_InitialCondition_lw
                    section.data(9).logicalSrcIdx = 657;
                    section.data(9).dtTransOffset = 8;

                    ;% UAM_Flight_control_P.Merge_8_InitialOutput_g
                    section.data(10).logicalSrcIdx = 658;
                    section.data(10).dtTransOffset = 9;

            nTotData = nTotData + section.nData;
            paramMap.sections(50) = section;
            clear section

            section.nData     = 13;
            section.data(13)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Merge_5_InitialOutput_e
                    section.data(1).logicalSrcIdx = 659;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_P.Merge_6_InitialOutput_e
                    section.data(2).logicalSrcIdx = 660;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_P.Merge_7_InitialOutput_e
                    section.data(3).logicalSrcIdx = 661;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_P.Merge_8_InitialOutput_e
                    section.data(4).logicalSrcIdx = 662;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_P.Merge_11_InitialOutput_e
                    section.data(5).logicalSrcIdx = 663;
                    section.data(5).dtTransOffset = 4;

                    ;% UAM_Flight_control_P.Merge_12_InitialOutput_e
                    section.data(6).logicalSrcIdx = 664;
                    section.data(6).dtTransOffset = 5;

                    ;% UAM_Flight_control_P.Merge_13_InitialOutput_e
                    section.data(7).logicalSrcIdx = 665;
                    section.data(7).dtTransOffset = 6;

                    ;% UAM_Flight_control_P.Merge_15_InitialOutput
                    section.data(8).logicalSrcIdx = 666;
                    section.data(8).dtTransOffset = 7;

                    ;% UAM_Flight_control_P.Merge_16_InitialOutput
                    section.data(9).logicalSrcIdx = 667;
                    section.data(9).dtTransOffset = 8;

                    ;% UAM_Flight_control_P.Merge_17_InitialOutput
                    section.data(10).logicalSrcIdx = 668;
                    section.data(10).dtTransOffset = 9;

                    ;% UAM_Flight_control_P.Merge_26_InitialOutput
                    section.data(11).logicalSrcIdx = 669;
                    section.data(11).dtTransOffset = 10;

                    ;% UAM_Flight_control_P.Merge_27_InitialOutput
                    section.data(12).logicalSrcIdx = 670;
                    section.data(12).dtTransOffset = 11;

                    ;% UAM_Flight_control_P.Merge_28_InitialOutput
                    section.data(13).logicalSrcIdx = 671;
                    section.data(13).dtTransOffset = 12;

            nTotData = nTotData + section.nData;
            paramMap.sections(51) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Merge_40_InitialOutput
                    section.data(1).logicalSrcIdx = 672;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_P.Merge_41_InitialOutput
                    section.data(2).logicalSrcIdx = 673;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_P.Merge_42_InitialOutput
                    section.data(3).logicalSrcIdx = 674;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_P.Merge_43_InitialOutput
                    section.data(4).logicalSrcIdx = 675;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_P.Merge_44_InitialOutput
                    section.data(5).logicalSrcIdx = 676;
                    section.data(5).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            paramMap.sections(52) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Constant_Value_hf
                    section.data(1).logicalSrcIdx = 677;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_P.Constant_Value_ad
                    section.data(2).logicalSrcIdx = 678;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_P.Constant_Value_ga
                    section.data(3).logicalSrcIdx = 679;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_P.Constant_Value_hg
                    section.data(4).logicalSrcIdx = 680;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_P.Constant_Value_nx
                    section.data(5).logicalSrcIdx = 681;
                    section.data(5).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            paramMap.sections(53) = section;
            clear section

            section.nData     = 28;
            section.data(28)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Constant_Value_jf
                    section.data(1).logicalSrcIdx = 682;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_P.Constant2_Value_h3
                    section.data(2).logicalSrcIdx = 683;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_P.Constant3_Value_ca
                    section.data(3).logicalSrcIdx = 684;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_P.Constant4_Value_c
                    section.data(4).logicalSrcIdx = 685;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_P.Constant_Value_mm
                    section.data(5).logicalSrcIdx = 686;
                    section.data(5).dtTransOffset = 4;

                    ;% UAM_Flight_control_P.Constant2_Value_l
                    section.data(6).logicalSrcIdx = 687;
                    section.data(6).dtTransOffset = 5;

                    ;% UAM_Flight_control_P.Constant3_Value_h
                    section.data(7).logicalSrcIdx = 688;
                    section.data(7).dtTransOffset = 6;

                    ;% UAM_Flight_control_P.Constant4_Value_in
                    section.data(8).logicalSrcIdx = 689;
                    section.data(8).dtTransOffset = 7;

                    ;% UAM_Flight_control_P.Constant_Value_pl
                    section.data(9).logicalSrcIdx = 690;
                    section.data(9).dtTransOffset = 8;

                    ;% UAM_Flight_control_P.Constant2_Value_a
                    section.data(10).logicalSrcIdx = 691;
                    section.data(10).dtTransOffset = 9;

                    ;% UAM_Flight_control_P.Constant3_Value_p
                    section.data(11).logicalSrcIdx = 692;
                    section.data(11).dtTransOffset = 10;

                    ;% UAM_Flight_control_P.Constant4_Value_m
                    section.data(12).logicalSrcIdx = 693;
                    section.data(12).dtTransOffset = 11;

                    ;% UAM_Flight_control_P.Constant_Value_nq
                    section.data(13).logicalSrcIdx = 694;
                    section.data(13).dtTransOffset = 12;

                    ;% UAM_Flight_control_P.Constant2_Value_g
                    section.data(14).logicalSrcIdx = 695;
                    section.data(14).dtTransOffset = 13;

                    ;% UAM_Flight_control_P.Constant3_Value_od
                    section.data(15).logicalSrcIdx = 696;
                    section.data(15).dtTransOffset = 14;

                    ;% UAM_Flight_control_P.Constant4_Value_h
                    section.data(16).logicalSrcIdx = 697;
                    section.data(16).dtTransOffset = 15;

                    ;% UAM_Flight_control_P.Constant_Value_fb
                    section.data(17).logicalSrcIdx = 698;
                    section.data(17).dtTransOffset = 16;

                    ;% UAM_Flight_control_P.Constant2_Value_ci
                    section.data(18).logicalSrcIdx = 699;
                    section.data(18).dtTransOffset = 17;

                    ;% UAM_Flight_control_P.Constant3_Value_m
                    section.data(19).logicalSrcIdx = 700;
                    section.data(19).dtTransOffset = 18;

                    ;% UAM_Flight_control_P.Constant4_Value_ci
                    section.data(20).logicalSrcIdx = 701;
                    section.data(20).dtTransOffset = 19;

                    ;% UAM_Flight_control_P.Constant_Value_pe
                    section.data(21).logicalSrcIdx = 702;
                    section.data(21).dtTransOffset = 20;

                    ;% UAM_Flight_control_P.Constant2_Value_b
                    section.data(22).logicalSrcIdx = 703;
                    section.data(22).dtTransOffset = 21;

                    ;% UAM_Flight_control_P.Constant3_Value_a
                    section.data(23).logicalSrcIdx = 704;
                    section.data(23).dtTransOffset = 22;

                    ;% UAM_Flight_control_P.Constant4_Value_jz
                    section.data(24).logicalSrcIdx = 705;
                    section.data(24).dtTransOffset = 23;

                    ;% UAM_Flight_control_P.Gain1_Gain_ms
                    section.data(25).logicalSrcIdx = 706;
                    section.data(25).dtTransOffset = 24;

                    ;% UAM_Flight_control_P.Gain1_Gain_dg
                    section.data(26).logicalSrcIdx = 707;
                    section.data(26).dtTransOffset = 25;

                    ;% UAM_Flight_control_P.DiscreteTimeIntegrator_IC
                    section.data(27).logicalSrcIdx = 708;
                    section.data(27).dtTransOffset = 26;

                    ;% UAM_Flight_control_P.DiscreteTimeIntegrator_IC_l
                    section.data(28).logicalSrcIdx = 709;
                    section.data(28).dtTransOffset = 27;

            nTotData = nTotData + section.nData;
            paramMap.sections(54) = section;
            clear section

            section.nData     = 26;
            section.data(26)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Gain_Gain_ck
                    section.data(1).logicalSrcIdx = 710;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_P.Gain_Gain_os
                    section.data(2).logicalSrcIdx = 711;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_P.UnitDelay_InitialCondition_l
                    section.data(3).logicalSrcIdx = 712;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_P.Switch_Threshold_g
                    section.data(4).logicalSrcIdx = 713;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_P.Switch_Threshold_c
                    section.data(5).logicalSrcIdx = 714;
                    section.data(5).dtTransOffset = 4;

                    ;% UAM_Flight_control_P.Switch1_Threshold
                    section.data(6).logicalSrcIdx = 715;
                    section.data(6).dtTransOffset = 5;

                    ;% UAM_Flight_control_P.Switch2_Threshold
                    section.data(7).logicalSrcIdx = 716;
                    section.data(7).dtTransOffset = 6;

                    ;% UAM_Flight_control_P.Switch4_Threshold
                    section.data(8).logicalSrcIdx = 717;
                    section.data(8).dtTransOffset = 7;

                    ;% UAM_Flight_control_P.UnitDelay_9_InitialCondition
                    section.data(9).logicalSrcIdx = 718;
                    section.data(9).dtTransOffset = 8;

                    ;% UAM_Flight_control_P.Constant3_Value_f
                    section.data(10).logicalSrcIdx = 719;
                    section.data(10).dtTransOffset = 9;

                    ;% UAM_Flight_control_P.Constant3_Value_k
                    section.data(11).logicalSrcIdx = 720;
                    section.data(11).dtTransOffset = 10;

                    ;% UAM_Flight_control_P.Constant_Value_lu
                    section.data(12).logicalSrcIdx = 721;
                    section.data(12).dtTransOffset = 11;

                    ;% UAM_Flight_control_P.Constant_Value_kd
                    section.data(13).logicalSrcIdx = 722;
                    section.data(13).dtTransOffset = 12;

                    ;% UAM_Flight_control_P.UnitDelay_9_InitialCondition_l
                    section.data(14).logicalSrcIdx = 723;
                    section.data(14).dtTransOffset = 13;

                    ;% UAM_Flight_control_P.UnitDelay_9_InitialCondition_lw
                    section.data(15).logicalSrcIdx = 724;
                    section.data(15).dtTransOffset = 14;

                    ;% UAM_Flight_control_P.Constant3_Value_pj
                    section.data(16).logicalSrcIdx = 725;
                    section.data(16).dtTransOffset = 15;

                    ;% UAM_Flight_control_P.Constant_Value_av
                    section.data(17).logicalSrcIdx = 726;
                    section.data(17).dtTransOffset = 16;

                    ;% UAM_Flight_control_P.IC_Value_h
                    section.data(18).logicalSrcIdx = 727;
                    section.data(18).dtTransOffset = 17;

                    ;% UAM_Flight_control_P.Constant2_Value_f
                    section.data(19).logicalSrcIdx = 728;
                    section.data(19).dtTransOffset = 18;

                    ;% UAM_Flight_control_P.UnitDelay_1_InitialCondition_e
                    section.data(20).logicalSrcIdx = 729;
                    section.data(20).dtTransOffset = 19;

                    ;% UAM_Flight_control_P.Merge_14_InitialOutput
                    section.data(21).logicalSrcIdx = 730;
                    section.data(21).dtTransOffset = 20;

                    ;% UAM_Flight_control_P.Merge_45_InitialOutput
                    section.data(22).logicalSrcIdx = 731;
                    section.data(22).dtTransOffset = 21;

                    ;% UAM_Flight_control_P.Merge_46_InitialOutput
                    section.data(23).logicalSrcIdx = 732;
                    section.data(23).dtTransOffset = 22;

                    ;% UAM_Flight_control_P.Merge_47_InitialOutput
                    section.data(24).logicalSrcIdx = 733;
                    section.data(24).dtTransOffset = 23;

                    ;% UAM_Flight_control_P.Merge_9_InitialOutput_g
                    section.data(25).logicalSrcIdx = 734;
                    section.data(25).dtTransOffset = 24;

                    ;% UAM_Flight_control_P.Merge_1_InitialOutput_l
                    section.data(26).logicalSrcIdx = 735;
                    section.data(26).dtTransOffset = 25;

            nTotData = nTotData + section.nData;
            paramMap.sections(55) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Emergency_b.Constant1_Value
                    section.data(1).logicalSrcIdx = 736;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(56) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Emergency_b.Constant2_Value
                    section.data(1).logicalSrcIdx = 737;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(57) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.Emergency_b.Constant3_Value
                    section.data(1).logicalSrcIdx = 738;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(58) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem.Constant1_Value
                    section.data(1).logicalSrcIdx = 739;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(59) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem.Constant2_Value
                    section.data(1).logicalSrcIdx = 740;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(60) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem.Constant3_Value
                    section.data(1).logicalSrcIdx = 741;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(61) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem2_n.Saturation2_UpperSat
                    section.data(1).logicalSrcIdx = 742;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem2_n.Saturation2_LowerSat
                    section.data(2).logicalSrcIdx = 743;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem2_n.Constant_Value
                    section.data(3).logicalSrcIdx = 744;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem2_n.Constant2_Value
                    section.data(4).logicalSrcIdx = 745;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem2_n.Constant3_Value
                    section.data(5).logicalSrcIdx = 746;
                    section.data(5).dtTransOffset = 4;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem2_n.Constant4_Value
                    section.data(6).logicalSrcIdx = 747;
                    section.data(6).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            paramMap.sections(62) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem3_g.Constant_Value
                    section.data(1).logicalSrcIdx = 748;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem3_g.Constant1_Value
                    section.data(2).logicalSrcIdx = 749;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem3_g.Constant2_Value
                    section.data(3).logicalSrcIdx = 750;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem3_g.Constant3_Value
                    section.data(4).logicalSrcIdx = 751;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            paramMap.sections(63) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem1_m.Constant_Value
                    section.data(1).logicalSrcIdx = 752;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem1_m.Constant1_Value
                    section.data(2).logicalSrcIdx = 753;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem1_m.Constant2_Value
                    section.data(3).logicalSrcIdx = 754;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem1_m.Constant3_Value
                    section.data(4).logicalSrcIdx = 755;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            paramMap.sections(64) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem1_m.Switch_Threshold
                    section.data(1).logicalSrcIdx = 756;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(65) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem_e.Constant_Value
                    section.data(1).logicalSrcIdx = 757;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem_e.Constant1_Value
                    section.data(2).logicalSrcIdx = 758;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem_e.Constant2_Value
                    section.data(3).logicalSrcIdx = 759;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem_e.Constant3_Value
                    section.data(4).logicalSrcIdx = 760;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            paramMap.sections(66) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem2_g.Saturation2_UpperSat
                    section.data(1).logicalSrcIdx = 761;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem2_g.Saturation2_LowerSat
                    section.data(2).logicalSrcIdx = 762;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem2_g.Constant_Value
                    section.data(3).logicalSrcIdx = 763;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem2_g.Constant2_Value
                    section.data(4).logicalSrcIdx = 764;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem2_g.Constant3_Value
                    section.data(5).logicalSrcIdx = 765;
                    section.data(5).dtTransOffset = 4;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem2_g.Constant4_Value
                    section.data(6).logicalSrcIdx = 766;
                    section.data(6).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            paramMap.sections(67) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem3_j.Constant_Value
                    section.data(1).logicalSrcIdx = 767;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem3_j.Constant1_Value
                    section.data(2).logicalSrcIdx = 768;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem3_j.Constant2_Value
                    section.data(3).logicalSrcIdx = 769;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem3_j.Constant3_Value
                    section.data(4).logicalSrcIdx = 770;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            paramMap.sections(68) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem_o.Constant_Value
                    section.data(1).logicalSrcIdx = 771;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem_o.Constant1_Value
                    section.data(2).logicalSrcIdx = 772;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem_o.Constant2_Value
                    section.data(3).logicalSrcIdx = 773;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem_o.Constant3_Value
                    section.data(4).logicalSrcIdx = 774;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            paramMap.sections(69) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem3.Constant_Value
                    section.data(1).logicalSrcIdx = 775;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem3.Constant1_Value
                    section.data(2).logicalSrcIdx = 776;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem3.Constant2_Value
                    section.data(3).logicalSrcIdx = 777;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem3.Constant3_Value
                    section.data(4).logicalSrcIdx = 778;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            paramMap.sections(70) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem1_e.Constant_Value
                    section.data(1).logicalSrcIdx = 779;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem1_e.Constant1_Value
                    section.data(2).logicalSrcIdx = 780;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem1_e.Constant2_Value
                    section.data(3).logicalSrcIdx = 781;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem1_e.Constant3_Value
                    section.data(4).logicalSrcIdx = 782;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            paramMap.sections(71) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem1_e.Switch_Threshold
                    section.data(1).logicalSrcIdx = 783;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(72) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem_kk.Constant_Value
                    section.data(1).logicalSrcIdx = 784;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem_kk.Constant1_Value
                    section.data(2).logicalSrcIdx = 785;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem_kk.Constant2_Value
                    section.data(3).logicalSrcIdx = 786;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_P.SwitchCaseActionSubsystem_kk.Constant3_Value
                    section.data(4).logicalSrcIdx = 787;
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
        nTotSects     = 15;
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

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_B.RotorParameters_g
                    section.data(1).logicalSrcIdx = 8;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(4) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% UAM_Flight_control_B.AACSP
                    section.data(1).logicalSrcIdx = 9;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_B.aacSP
                    section.data(2).logicalSrcIdx = 10;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            sigMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_B.HoverSPBUS
                    section.data(1).logicalSrcIdx = 11;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(6) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% UAM_Flight_control_B.CtrlSurfaceCommands
                    section.data(1).logicalSrcIdx = 12;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_B.Merge
                    section.data(2).logicalSrcIdx = 13;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_B.OutportBufferForCtrlSurfaceComm
                    section.data(3).logicalSrcIdx = 14;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_B.Merge_n
                    section.data(4).logicalSrcIdx = 15;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_B.OutportBufferForCtrlSurfaceCo_i
                    section.data(5).logicalSrcIdx = 16;
                    section.data(5).dtTransOffset = 4;

                    ;% UAM_Flight_control_B.Merge_d
                    section.data(6).logicalSrcIdx = 17;
                    section.data(6).dtTransOffset = 5;

                    ;% UAM_Flight_control_B.OutportBufferForCtrlSurfaceC_i5
                    section.data(7).logicalSrcIdx = 18;
                    section.data(7).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            sigMap.sections(7) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% UAM_Flight_control_B.FixedWingSP
                    section.data(1).logicalSrcIdx = 19;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_B.FixedWingSP_p
                    section.data(2).logicalSrcIdx = 20;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            sigMap.sections(8) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% UAM_Flight_control_B.controlMode_h
                    section.data(1).logicalSrcIdx = 21;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_B.controlMode_o
                    section.data(2).logicalSrcIdx = 22;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_B.controlMode_e
                    section.data(3).logicalSrcIdx = 23;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_B.controlMode_l
                    section.data(4).logicalSrcIdx = 24;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            sigMap.sections(9) = section;
            clear section

            section.nData     = 317;
            section.data(317)  = dumData; %prealloc

                    ;% UAM_Flight_control_B.GPSCourse
                    section.data(1).logicalSrcIdx = 25;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_B.TmpSignalConversionAtToWorkspac
                    section.data(2).logicalSrcIdx = 26;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_B.rc
                    section.data(3).logicalSrcIdx = 27;
                    section.data(3).dtTransOffset = 9;

                    ;% UAM_Flight_control_B.Gain1
                    section.data(4).logicalSrcIdx = 28;
                    section.data(4).dtTransOffset = 25;

                    ;% UAM_Flight_control_B.YPR
                    section.data(5).logicalSrcIdx = 29;
                    section.data(5).dtTransOffset = 28;

                    ;% UAM_Flight_control_B.acc_x
                    section.data(6).logicalSrcIdx = 30;
                    section.data(6).dtTransOffset = 31;

                    ;% UAM_Flight_control_B.acc_y
                    section.data(7).logicalSrcIdx = 31;
                    section.data(7).dtTransOffset = 32;

                    ;% UAM_Flight_control_B.acc_z
                    section.data(8).logicalSrcIdx = 32;
                    section.data(8).dtTransOffset = 33;

                    ;% UAM_Flight_control_B.Abb
                    section.data(9).logicalSrcIdx = 33;
                    section.data(9).dtTransOffset = 34;

                    ;% UAM_Flight_control_B.gyro_x
                    section.data(10).logicalSrcIdx = 34;
                    section.data(10).dtTransOffset = 37;

                    ;% UAM_Flight_control_B.gyro_y
                    section.data(11).logicalSrcIdx = 35;
                    section.data(11).dtTransOffset = 38;

                    ;% UAM_Flight_control_B.gyro_z
                    section.data(12).logicalSrcIdx = 36;
                    section.data(12).dtTransOffset = 39;

                    ;% UAM_Flight_control_B.Gyro
                    section.data(13).logicalSrcIdx = 37;
                    section.data(13).dtTransOffset = 40;

                    ;% UAM_Flight_control_B.pqr
                    section.data(14).logicalSrcIdx = 38;
                    section.data(14).dtTransOffset = 43;

                    ;% UAM_Flight_control_B.vel_n
                    section.data(15).logicalSrcIdx = 39;
                    section.data(15).dtTransOffset = 46;

                    ;% UAM_Flight_control_B.vel_e
                    section.data(16).logicalSrcIdx = 40;
                    section.data(16).dtTransOffset = 47;

                    ;% UAM_Flight_control_B.pressure
                    section.data(17).logicalSrcIdx = 41;
                    section.data(17).dtTransOffset = 48;

                    ;% UAM_Flight_control_B.arm
                    section.data(18).logicalSrcIdx = 42;
                    section.data(18).dtTransOffset = 49;

                    ;% UAM_Flight_control_B.Sum19
                    section.data(19).logicalSrcIdx = 43;
                    section.data(19).dtTransOffset = 50;

                    ;% UAM_Flight_control_B.Sum23
                    section.data(20).logicalSrcIdx = 44;
                    section.data(20).dtTransOffset = 51;

                    ;% UAM_Flight_control_B.GPSVelocity
                    section.data(21).logicalSrcIdx = 45;
                    section.data(21).dtTransOffset = 52;

                    ;% UAM_Flight_control_B.Ve
                    section.data(22).logicalSrcIdx = 46;
                    section.data(22).dtTransOffset = 55;

                    ;% UAM_Flight_control_B.latitude
                    section.data(23).logicalSrcIdx = 47;
                    section.data(23).dtTransOffset = 58;

                    ;% UAM_Flight_control_B.longitude
                    section.data(24).logicalSrcIdx = 48;
                    section.data(24).dtTransOffset = 59;

                    ;% UAM_Flight_control_B.Sum22
                    section.data(25).logicalSrcIdx = 49;
                    section.data(25).dtTransOffset = 60;

                    ;% UAM_Flight_control_B.Xe
                    section.data(26).logicalSrcIdx = 50;
                    section.data(26).dtTransOffset = 61;

                    ;% UAM_Flight_control_B.airspeed
                    section.data(27).logicalSrcIdx = 51;
                    section.data(27).dtTransOffset = 64;

                    ;% UAM_Flight_control_B.gndspeed
                    section.data(28).logicalSrcIdx = 52;
                    section.data(28).dtTransOffset = 65;

                    ;% UAM_Flight_control_B.gndspeed_g
                    section.data(29).logicalSrcIdx = 53;
                    section.data(29).dtTransOffset = 66;

                    ;% UAM_Flight_control_B.course
                    section.data(30).logicalSrcIdx = 54;
                    section.data(30).dtTransOffset = 67;

                    ;% UAM_Flight_control_B.RC
                    section.data(31).logicalSrcIdx = 55;
                    section.data(31).dtTransOffset = 68;

                    ;% UAM_Flight_control_B.pose
                    section.data(32).logicalSrcIdx = 56;
                    section.data(32).dtTransOffset = 78;

                    ;% UAM_Flight_control_B.UnitDelay2
                    section.data(33).logicalSrcIdx = 57;
                    section.data(33).dtTransOffset = 82;

                    ;% UAM_Flight_control_B.ground
                    section.data(34).logicalSrcIdx = 58;
                    section.data(34).dtTransOffset = 83;

                    ;% UAM_Flight_control_B.pose_b
                    section.data(35).logicalSrcIdx = 59;
                    section.data(35).dtTransOffset = 84;

                    ;% UAM_Flight_control_B.RateTransition5
                    section.data(36).logicalSrcIdx = 60;
                    section.data(36).dtTransOffset = 88;

                    ;% UAM_Flight_control_B.X
                    section.data(37).logicalSrcIdx = 61;
                    section.data(37).dtTransOffset = 89;

                    ;% UAM_Flight_control_B.Y
                    section.data(38).logicalSrcIdx = 62;
                    section.data(38).dtTransOffset = 90;

                    ;% UAM_Flight_control_B.Z
                    section.data(39).logicalSrcIdx = 63;
                    section.data(39).dtTransOffset = 91;

                    ;% UAM_Flight_control_B.Yaw
                    section.data(40).logicalSrcIdx = 64;
                    section.data(40).dtTransOffset = 92;

                    ;% UAM_Flight_control_B.roll
                    section.data(41).logicalSrcIdx = 65;
                    section.data(41).dtTransOffset = 93;

                    ;% UAM_Flight_control_B.pitch
                    section.data(42).logicalSrcIdx = 66;
                    section.data(42).dtTransOffset = 94;

                    ;% UAM_Flight_control_B.yaw
                    section.data(43).logicalSrcIdx = 67;
                    section.data(43).dtTransOffset = 95;

                    ;% UAM_Flight_control_B.altitude
                    section.data(44).logicalSrcIdx = 68;
                    section.data(44).dtTransOffset = 96;

                    ;% UAM_Flight_control_B.latitude_m
                    section.data(45).logicalSrcIdx = 69;
                    section.data(45).dtTransOffset = 97;

                    ;% UAM_Flight_control_B.longitude_f
                    section.data(46).logicalSrcIdx = 70;
                    section.data(46).dtTransOffset = 98;

                    ;% UAM_Flight_control_B.acc_x_f
                    section.data(47).logicalSrcIdx = 71;
                    section.data(47).dtTransOffset = 99;

                    ;% UAM_Flight_control_B.acc_y_j
                    section.data(48).logicalSrcIdx = 72;
                    section.data(48).dtTransOffset = 100;

                    ;% UAM_Flight_control_B.acc_z_l
                    section.data(49).logicalSrcIdx = 73;
                    section.data(49).dtTransOffset = 101;

                    ;% UAM_Flight_control_B.pressure_c
                    section.data(50).logicalSrcIdx = 74;
                    section.data(50).dtTransOffset = 102;

                    ;% UAM_Flight_control_B.vel_n_j
                    section.data(51).logicalSrcIdx = 75;
                    section.data(51).dtTransOffset = 103;

                    ;% UAM_Flight_control_B.vel_e_b
                    section.data(52).logicalSrcIdx = 76;
                    section.data(52).dtTransOffset = 104;

                    ;% UAM_Flight_control_B.vel_d
                    section.data(53).logicalSrcIdx = 77;
                    section.data(53).dtTransOffset = 105;

                    ;% UAM_Flight_control_B.gndspeed_f
                    section.data(54).logicalSrcIdx = 78;
                    section.data(54).dtTransOffset = 106;

                    ;% UAM_Flight_control_B.gyro_x_j
                    section.data(55).logicalSrcIdx = 79;
                    section.data(55).dtTransOffset = 107;

                    ;% UAM_Flight_control_B.gyro_y_j
                    section.data(56).logicalSrcIdx = 80;
                    section.data(56).dtTransOffset = 108;

                    ;% UAM_Flight_control_B.gyro_z_d
                    section.data(57).logicalSrcIdx = 81;
                    section.data(57).dtTransOffset = 109;

                    ;% UAM_Flight_control_B.mag_x
                    section.data(58).logicalSrcIdx = 82;
                    section.data(58).dtTransOffset = 110;

                    ;% UAM_Flight_control_B.mag_y
                    section.data(59).logicalSrcIdx = 83;
                    section.data(59).dtTransOffset = 111;

                    ;% UAM_Flight_control_B.mag_z
                    section.data(60).logicalSrcIdx = 84;
                    section.data(60).dtTransOffset = 112;

                    ;% UAM_Flight_control_B.lin_acc_ecef_x
                    section.data(61).logicalSrcIdx = 85;
                    section.data(61).dtTransOffset = 113;

                    ;% UAM_Flight_control_B.lin_acc_ecef_y
                    section.data(62).logicalSrcIdx = 86;
                    section.data(62).dtTransOffset = 114;

                    ;% UAM_Flight_control_B.lin_acc_ecef_z
                    section.data(63).logicalSrcIdx = 87;
                    section.data(63).dtTransOffset = 115;

                    ;% UAM_Flight_control_B.q
                    section.data(64).logicalSrcIdx = 88;
                    section.data(64).dtTransOffset = 116;

                    ;% UAM_Flight_control_B.airspeed_c
                    section.data(65).logicalSrcIdx = 89;
                    section.data(65).dtTransOffset = 120;

                    ;% UAM_Flight_control_B.m
                    section.data(66).logicalSrcIdx = 90;
                    section.data(66).dtTransOffset = 121;

                    ;% UAM_Flight_control_B.rc_j
                    section.data(67).logicalSrcIdx = 91;
                    section.data(67).dtTransOffset = 127;

                    ;% UAM_Flight_control_B.rpy_sp
                    section.data(68).logicalSrcIdx = 92;
                    section.data(68).dtTransOffset = 143;

                    ;% UAM_Flight_control_B.mag_x_i
                    section.data(69).logicalSrcIdx = 93;
                    section.data(69).dtTransOffset = 146;

                    ;% UAM_Flight_control_B.mag_y_a
                    section.data(70).logicalSrcIdx = 94;
                    section.data(70).dtTransOffset = 147;

                    ;% UAM_Flight_control_B.mag_z_o
                    section.data(71).logicalSrcIdx = 95;
                    section.data(71).dtTransOffset = 148;

                    ;% UAM_Flight_control_B.q_d
                    section.data(72).logicalSrcIdx = 96;
                    section.data(72).dtTransOffset = 149;

                    ;% UAM_Flight_control_B.a
                    section.data(73).logicalSrcIdx = 98;
                    section.data(73).dtTransOffset = 153;

                    ;% UAM_Flight_control_B.RC_a
                    section.data(74).logicalSrcIdx = 99;
                    section.data(74).dtTransOffset = 154;

                    ;% UAM_Flight_control_B.target
                    section.data(75).logicalSrcIdx = 100;
                    section.data(75).dtTransOffset = 164;

                    ;% UAM_Flight_control_B.ground_o
                    section.data(76).logicalSrcIdx = 101;
                    section.data(76).dtTransOffset = 167;

                    ;% UAM_Flight_control_B.pose_h
                    section.data(77).logicalSrcIdx = 102;
                    section.data(77).dtTransOffset = 168;

                    ;% UAM_Flight_control_B.Euler
                    section.data(78).logicalSrcIdx = 103;
                    section.data(78).dtTransOffset = 172;

                    ;% UAM_Flight_control_B.pqr_n
                    section.data(79).logicalSrcIdx = 104;
                    section.data(79).dtTransOffset = 175;

                    ;% UAM_Flight_control_B.Ve_o
                    section.data(80).logicalSrcIdx = 105;
                    section.data(80).dtTransOffset = 178;

                    ;% UAM_Flight_control_B.Xe_i
                    section.data(81).logicalSrcIdx = 106;
                    section.data(81).dtTransOffset = 181;

                    ;% UAM_Flight_control_B.course_k
                    section.data(82).logicalSrcIdx = 107;
                    section.data(82).dtTransOffset = 184;

                    ;% UAM_Flight_control_B.Mag
                    section.data(83).logicalSrcIdx = 108;
                    section.data(83).dtTransOffset = 185;

                    ;% UAM_Flight_control_B.Abe
                    section.data(84).logicalSrcIdx = 109;
                    section.data(84).dtTransOffset = 188;

                    ;% UAM_Flight_control_B.gps_valid
                    section.data(85).logicalSrcIdx = 110;
                    section.data(85).dtTransOffset = 191;

                    ;% UAM_Flight_control_B.baro_valid
                    section.data(86).logicalSrcIdx = 111;
                    section.data(86).dtTransOffset = 192;

                    ;% UAM_Flight_control_B.mag_valid
                    section.data(87).logicalSrcIdx = 112;
                    section.data(87).dtTransOffset = 193;

                    ;% UAM_Flight_control_B.z_lpf
                    section.data(88).logicalSrcIdx = 113;
                    section.data(88).dtTransOffset = 194;

                    ;% UAM_Flight_control_B.z_baro
                    section.data(89).logicalSrcIdx = 114;
                    section.data(89).dtTransOffset = 195;

                    ;% UAM_Flight_control_B.P0_Pa
                    section.data(90).logicalSrcIdx = 115;
                    section.data(90).dtTransOffset = 196;

                    ;% UAM_Flight_control_B.pos_out
                    section.data(91).logicalSrcIdx = 119;
                    section.data(91).dtTransOffset = 197;

                    ;% UAM_Flight_control_B.vel_out
                    section.data(92).logicalSrcIdx = 120;
                    section.data(92).dtTransOffset = 200;

                    ;% UAM_Flight_control_B.gyro_bias_out
                    section.data(93).logicalSrcIdx = 122;
                    section.data(93).dtTransOffset = 203;

                    ;% UAM_Flight_control_B.accel_bias_out
                    section.data(94).logicalSrcIdx = 123;
                    section.data(94).dtTransOffset = 206;

                    ;% UAM_Flight_control_B.baro_bias_out
                    section.data(95).logicalSrcIdx = 129;
                    section.data(95).dtTransOffset = 209;

                    ;% UAM_Flight_control_B.Reshape
                    section.data(96).logicalSrcIdx = 131;
                    section.data(96).dtTransOffset = 210;

                    ;% UAM_Flight_control_B.TmpSignalConversionAtWaypointFo
                    section.data(97).logicalSrcIdx = 132;
                    section.data(97).dtTransOffset = 213;

                    ;% UAM_Flight_control_B.LAP
                    section.data(98).logicalSrcIdx = 133;
                    section.data(98).dtTransOffset = 217;

                    ;% UAM_Flight_control_B.course_b
                    section.data(99).logicalSrcIdx = 134;
                    section.data(99).dtTransOffset = 220;

                    ;% UAM_Flight_control_B.wps
                    section.data(100).logicalSrcIdx = 135;
                    section.data(100).dtTransOffset = 221;

                    ;% UAM_Flight_control_B.X_h
                    section.data(101).logicalSrcIdx = 136;
                    section.data(101).dtTransOffset = 227;

                    ;% UAM_Flight_control_B.Y_i
                    section.data(102).logicalSrcIdx = 137;
                    section.data(102).dtTransOffset = 228;

                    ;% UAM_Flight_control_B.Z_n
                    section.data(103).logicalSrcIdx = 138;
                    section.data(103).dtTransOffset = 229;

                    ;% UAM_Flight_control_B.Yaw_g
                    section.data(104).logicalSrcIdx = 139;
                    section.data(104).dtTransOffset = 230;

                    ;% UAM_Flight_control_B.Gain
                    section.data(105).logicalSrcIdx = 140;
                    section.data(105).dtTransOffset = 231;

                    ;% UAM_Flight_control_B.t_p
                    section.data(106).logicalSrcIdx = 141;
                    section.data(106).dtTransOffset = 234;

                    ;% UAM_Flight_control_B.e_q
                    section.data(107).logicalSrcIdx = 142;
                    section.data(107).dtTransOffset = 235;

                    ;% UAM_Flight_control_B.e_r
                    section.data(108).logicalSrcIdx = 143;
                    section.data(108).dtTransOffset = 236;

                    ;% UAM_Flight_control_B.Sum
                    section.data(109).logicalSrcIdx = 144;
                    section.data(109).dtTransOffset = 237;

                    ;% UAM_Flight_control_B.Gain_g
                    section.data(110).logicalSrcIdx = 145;
                    section.data(110).dtTransOffset = 238;

                    ;% UAM_Flight_control_B.l_x
                    section.data(111).logicalSrcIdx = 146;
                    section.data(111).dtTransOffset = 239;

                    ;% UAM_Flight_control_B.w1
                    section.data(112).logicalSrcIdx = 147;
                    section.data(112).dtTransOffset = 240;

                    ;% UAM_Flight_control_B.w2
                    section.data(113).logicalSrcIdx = 148;
                    section.data(113).dtTransOffset = 241;

                    ;% UAM_Flight_control_B.w3
                    section.data(114).logicalSrcIdx = 149;
                    section.data(114).dtTransOffset = 242;

                    ;% UAM_Flight_control_B.w4
                    section.data(115).logicalSrcIdx = 150;
                    section.data(115).dtTransOffset = 243;

                    ;% UAM_Flight_control_B.c1
                    section.data(116).logicalSrcIdx = 151;
                    section.data(116).dtTransOffset = 244;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreator_
                    section.data(117).logicalSrcIdx = 152;
                    section.data(117).dtTransOffset = 245;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_e
                    section.data(118).logicalSrcIdx = 153;
                    section.data(118).dtTransOffset = 246;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_d
                    section.data(119).logicalSrcIdx = 154;
                    section.data(119).dtTransOffset = 247;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_g
                    section.data(120).logicalSrcIdx = 155;
                    section.data(120).dtTransOffset = 248;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_n
                    section.data(121).logicalSrcIdx = 156;
                    section.data(121).dtTransOffset = 249;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_i
                    section.data(122).logicalSrcIdx = 157;
                    section.data(122).dtTransOffset = 250;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_dg
                    section.data(123).logicalSrcIdx = 158;
                    section.data(123).dtTransOffset = 251;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_a
                    section.data(124).logicalSrcIdx = 159;
                    section.data(124).dtTransOffset = 252;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_b
                    section.data(125).logicalSrcIdx = 160;
                    section.data(125).dtTransOffset = 253;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_j
                    section.data(126).logicalSrcIdx = 161;
                    section.data(126).dtTransOffset = 254;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_n2
                    section.data(127).logicalSrcIdx = 162;
                    section.data(127).dtTransOffset = 255;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_gx
                    section.data(128).logicalSrcIdx = 163;
                    section.data(128).dtTransOffset = 256;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ad
                    section.data(129).logicalSrcIdx = 164;
                    section.data(129).dtTransOffset = 257;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_bb
                    section.data(130).logicalSrcIdx = 165;
                    section.data(130).dtTransOffset = 258;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_p
                    section.data(131).logicalSrcIdx = 166;
                    section.data(131).dtTransOffset = 259;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_pd
                    section.data(132).logicalSrcIdx = 167;
                    section.data(132).dtTransOffset = 260;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_f
                    section.data(133).logicalSrcIdx = 168;
                    section.data(133).dtTransOffset = 261;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_by
                    section.data(134).logicalSrcIdx = 169;
                    section.data(134).dtTransOffset = 262;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_c
                    section.data(135).logicalSrcIdx = 170;
                    section.data(135).dtTransOffset = 263;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_du
                    section.data(136).logicalSrcIdx = 171;
                    section.data(136).dtTransOffset = 264;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_b5
                    section.data(137).logicalSrcIdx = 172;
                    section.data(137).dtTransOffset = 265;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_aw
                    section.data(138).logicalSrcIdx = 173;
                    section.data(138).dtTransOffset = 269;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_jx
                    section.data(139).logicalSrcIdx = 174;
                    section.data(139).dtTransOffset = 270;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_cv
                    section.data(140).logicalSrcIdx = 175;
                    section.data(140).dtTransOffset = 271;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_fp
                    section.data(141).logicalSrcIdx = 176;
                    section.data(141).dtTransOffset = 287;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_on
                    section.data(142).logicalSrcIdx = 178;
                    section.data(142).dtTransOffset = 290;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_da
                    section.data(143).logicalSrcIdx = 179;
                    section.data(143).dtTransOffset = 291;

                    ;% UAM_Flight_control_B.VectorConcatenate
                    section.data(144).logicalSrcIdx = 180;
                    section.data(144).dtTransOffset = 292;

                    ;% UAM_Flight_control_B.Gain1_p
                    section.data(145).logicalSrcIdx = 181;
                    section.data(145).dtTransOffset = 298;

                    ;% UAM_Flight_control_B.Saturation2
                    section.data(146).logicalSrcIdx = 182;
                    section.data(146).dtTransOffset = 299;

                    ;% UAM_Flight_control_B.Gain2
                    section.data(147).logicalSrcIdx = 183;
                    section.data(147).dtTransOffset = 300;

                    ;% UAM_Flight_control_B.Gain3
                    section.data(148).logicalSrcIdx = 184;
                    section.data(148).dtTransOffset = 301;

                    ;% UAM_Flight_control_B.Constant4
                    section.data(149).logicalSrcIdx = 185;
                    section.data(149).dtTransOffset = 302;

                    ;% UAM_Flight_control_B.TmpBufferAtConstant4Outport1
                    section.data(150).logicalSrcIdx = 186;
                    section.data(150).dtTransOffset = 303;

                    ;% UAM_Flight_control_B.Gain5
                    section.data(151).logicalSrcIdx = 187;
                    section.data(151).dtTransOffset = 304;

                    ;% UAM_Flight_control_B.dA
                    section.data(152).logicalSrcIdx = 188;
                    section.data(152).dtTransOffset = 305;

                    ;% UAM_Flight_control_B.dE
                    section.data(153).logicalSrcIdx = 189;
                    section.data(153).dtTransOffset = 306;

                    ;% UAM_Flight_control_B.dR
                    section.data(154).logicalSrcIdx = 190;
                    section.data(154).dtTransOffset = 307;

                    ;% UAM_Flight_control_B.dT
                    section.data(155).logicalSrcIdx = 191;
                    section.data(155).dtTransOffset = 308;

                    ;% UAM_Flight_control_B.dE_j
                    section.data(156).logicalSrcIdx = 192;
                    section.data(156).dtTransOffset = 309;

                    ;% UAM_Flight_control_B.Saturation
                    section.data(157).logicalSrcIdx = 193;
                    section.data(157).dtTransOffset = 310;

                    ;% UAM_Flight_control_B.Saturation2_m
                    section.data(158).logicalSrcIdx = 194;
                    section.data(158).dtTransOffset = 311;

                    ;% UAM_Flight_control_B.cruise
                    section.data(159).logicalSrcIdx = 195;
                    section.data(159).dtTransOffset = 312;

                    ;% UAM_Flight_control_B.w1_n
                    section.data(160).logicalSrcIdx = 196;
                    section.data(160).dtTransOffset = 313;

                    ;% UAM_Flight_control_B.w2_n
                    section.data(161).logicalSrcIdx = 197;
                    section.data(161).dtTransOffset = 314;

                    ;% UAM_Flight_control_B.w3_p
                    section.data(162).logicalSrcIdx = 198;
                    section.data(162).dtTransOffset = 315;

                    ;% UAM_Flight_control_B.w4_e
                    section.data(163).logicalSrcIdx = 199;
                    section.data(163).dtTransOffset = 316;

                    ;% UAM_Flight_control_B.c1_n
                    section.data(164).logicalSrcIdx = 200;
                    section.data(164).dtTransOffset = 317;

                    ;% UAM_Flight_control_B.VectorConcatenate_g
                    section.data(165).logicalSrcIdx = 201;
                    section.data(165).dtTransOffset = 318;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_cv2
                    section.data(166).logicalSrcIdx = 202;
                    section.data(166).dtTransOffset = 324;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ez
                    section.data(167).logicalSrcIdx = 203;
                    section.data(167).dtTransOffset = 325;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_de
                    section.data(168).logicalSrcIdx = 204;
                    section.data(168).dtTransOffset = 326;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_gb
                    section.data(169).logicalSrcIdx = 205;
                    section.data(169).dtTransOffset = 327;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_nw
                    section.data(170).logicalSrcIdx = 206;
                    section.data(170).dtTransOffset = 328;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_i0
                    section.data(171).logicalSrcIdx = 207;
                    section.data(171).dtTransOffset = 329;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_dgz
                    section.data(172).logicalSrcIdx = 208;
                    section.data(172).dtTransOffset = 330;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ae
                    section.data(173).logicalSrcIdx = 209;
                    section.data(173).dtTransOffset = 331;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_bj
                    section.data(174).logicalSrcIdx = 210;
                    section.data(174).dtTransOffset = 332;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_jj
                    section.data(175).logicalSrcIdx = 211;
                    section.data(175).dtTransOffset = 333;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_n2x
                    section.data(176).logicalSrcIdx = 212;
                    section.data(176).dtTransOffset = 334;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_gx0
                    section.data(177).logicalSrcIdx = 213;
                    section.data(177).dtTransOffset = 335;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_adl
                    section.data(178).logicalSrcIdx = 214;
                    section.data(178).dtTransOffset = 336;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_bbr
                    section.data(179).logicalSrcIdx = 215;
                    section.data(179).dtTransOffset = 337;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_py
                    section.data(180).logicalSrcIdx = 216;
                    section.data(180).dtTransOffset = 338;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_pds
                    section.data(181).logicalSrcIdx = 217;
                    section.data(181).dtTransOffset = 339;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_fs
                    section.data(182).logicalSrcIdx = 218;
                    section.data(182).dtTransOffset = 340;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_by1
                    section.data(183).logicalSrcIdx = 219;
                    section.data(183).dtTransOffset = 341;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_cr
                    section.data(184).logicalSrcIdx = 220;
                    section.data(184).dtTransOffset = 342;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_duz
                    section.data(185).logicalSrcIdx = 221;
                    section.data(185).dtTransOffset = 343;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_b55
                    section.data(186).logicalSrcIdx = 222;
                    section.data(186).dtTransOffset = 344;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_awy
                    section.data(187).logicalSrcIdx = 223;
                    section.data(187).dtTransOffset = 348;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_jx3
                    section.data(188).logicalSrcIdx = 224;
                    section.data(188).dtTransOffset = 349;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_cvb
                    section.data(189).logicalSrcIdx = 225;
                    section.data(189).dtTransOffset = 350;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_fp5
                    section.data(190).logicalSrcIdx = 226;
                    section.data(190).dtTransOffset = 366;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_oni
                    section.data(191).logicalSrcIdx = 228;
                    section.data(191).dtTransOffset = 369;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_dax
                    section.data(192).logicalSrcIdx = 229;
                    section.data(192).dtTransOffset = 370;

                    ;% UAM_Flight_control_B.Gain1_b
                    section.data(193).logicalSrcIdx = 230;
                    section.data(193).dtTransOffset = 371;

                    ;% UAM_Flight_control_B.Gain2_j
                    section.data(194).logicalSrcIdx = 231;
                    section.data(194).dtTransOffset = 372;

                    ;% UAM_Flight_control_B.Gain3_o
                    section.data(195).logicalSrcIdx = 232;
                    section.data(195).dtTransOffset = 373;

                    ;% UAM_Flight_control_B.Gain4
                    section.data(196).logicalSrcIdx = 233;
                    section.data(196).dtTransOffset = 374;

                    ;% UAM_Flight_control_B.Add2
                    section.data(197).logicalSrcIdx = 234;
                    section.data(197).dtTransOffset = 375;

                    ;% UAM_Flight_control_B.Gain3_m
                    section.data(198).logicalSrcIdx = 235;
                    section.data(198).dtTransOffset = 376;

                    ;% UAM_Flight_control_B.Add1
                    section.data(199).logicalSrcIdx = 236;
                    section.data(199).dtTransOffset = 377;

                    ;% UAM_Flight_control_B.Gain2_b
                    section.data(200).logicalSrcIdx = 237;
                    section.data(200).dtTransOffset = 378;

                    ;% UAM_Flight_control_B.Add3
                    section.data(201).logicalSrcIdx = 238;
                    section.data(201).dtTransOffset = 379;

                    ;% UAM_Flight_control_B.Gain4_f
                    section.data(202).logicalSrcIdx = 239;
                    section.data(202).dtTransOffset = 380;

                    ;% UAM_Flight_control_B.Add
                    section.data(203).logicalSrcIdx = 240;
                    section.data(203).dtTransOffset = 381;

                    ;% UAM_Flight_control_B.Gain1_m
                    section.data(204).logicalSrcIdx = 241;
                    section.data(204).dtTransOffset = 382;

                    ;% UAM_Flight_control_B.Add1_c
                    section.data(205).logicalSrcIdx = 242;
                    section.data(205).dtTransOffset = 383;

                    ;% UAM_Flight_control_B.Saturation4
                    section.data(206).logicalSrcIdx = 243;
                    section.data(206).dtTransOffset = 384;

                    ;% UAM_Flight_control_B.Sqrt1
                    section.data(207).logicalSrcIdx = 244;
                    section.data(207).dtTransOffset = 385;

                    ;% UAM_Flight_control_B.Gain1_g
                    section.data(208).logicalSrcIdx = 245;
                    section.data(208).dtTransOffset = 386;

                    ;% UAM_Flight_control_B.Add3_k
                    section.data(209).logicalSrcIdx = 246;
                    section.data(209).dtTransOffset = 387;

                    ;% UAM_Flight_control_B.Saturation2_p
                    section.data(210).logicalSrcIdx = 247;
                    section.data(210).dtTransOffset = 388;

                    ;% UAM_Flight_control_B.Sqrt4
                    section.data(211).logicalSrcIdx = 248;
                    section.data(211).dtTransOffset = 389;

                    ;% UAM_Flight_control_B.Gain4_n
                    section.data(212).logicalSrcIdx = 249;
                    section.data(212).dtTransOffset = 390;

                    ;% UAM_Flight_control_B.Add2_m
                    section.data(213).logicalSrcIdx = 250;
                    section.data(213).dtTransOffset = 391;

                    ;% UAM_Flight_control_B.Saturation1
                    section.data(214).logicalSrcIdx = 251;
                    section.data(214).dtTransOffset = 392;

                    ;% UAM_Flight_control_B.Sqrt2
                    section.data(215).logicalSrcIdx = 252;
                    section.data(215).dtTransOffset = 393;

                    ;% UAM_Flight_control_B.Gain2_l
                    section.data(216).logicalSrcIdx = 253;
                    section.data(216).dtTransOffset = 394;

                    ;% UAM_Flight_control_B.Add_n
                    section.data(217).logicalSrcIdx = 254;
                    section.data(217).dtTransOffset = 395;

                    ;% UAM_Flight_control_B.Saturation3
                    section.data(218).logicalSrcIdx = 255;
                    section.data(218).dtTransOffset = 396;

                    ;% UAM_Flight_control_B.Sqrt3
                    section.data(219).logicalSrcIdx = 256;
                    section.data(219).dtTransOffset = 397;

                    ;% UAM_Flight_control_B.Gain3_j
                    section.data(220).logicalSrcIdx = 257;
                    section.data(220).dtTransOffset = 398;

                    ;% UAM_Flight_control_B.Sum_j
                    section.data(221).logicalSrcIdx = 258;
                    section.data(221).dtTransOffset = 399;

                    ;% UAM_Flight_control_B.Merge_j
                    section.data(222).logicalSrcIdx = 259;
                    section.data(222).dtTransOffset = 400;

                    ;% UAM_Flight_control_B.Merge1
                    section.data(223).logicalSrcIdx = 260;
                    section.data(223).dtTransOffset = 401;

                    ;% UAM_Flight_control_B.Sum_d
                    section.data(224).logicalSrcIdx = 261;
                    section.data(224).dtTransOffset = 402;

                    ;% UAM_Flight_control_B.Sum_g
                    section.data(225).logicalSrcIdx = 262;
                    section.data(225).dtTransOffset = 403;

                    ;% UAM_Flight_control_B.Sum_dn
                    section.data(226).logicalSrcIdx = 263;
                    section.data(226).dtTransOffset = 404;

                    ;% UAM_Flight_control_B.AltHold
                    section.data(227).logicalSrcIdx = 264;
                    section.data(227).dtTransOffset = 405;

                    ;% UAM_Flight_control_B.altitude_k
                    section.data(228).logicalSrcIdx = 265;
                    section.data(228).dtTransOffset = 406;

                    ;% UAM_Flight_control_B.PitchSPMerge
                    section.data(229).logicalSrcIdx = 266;
                    section.data(229).dtTransOffset = 407;

                    ;% UAM_Flight_control_B.L1
                    section.data(230).logicalSrcIdx = 267;
                    section.data(230).dtTransOffset = 408;

                    ;% UAM_Flight_control_B.RollSPMerge
                    section.data(231).logicalSrcIdx = 268;
                    section.data(231).dtTransOffset = 409;

                    ;% UAM_Flight_control_B.ActuatordTMerge
                    section.data(232).logicalSrcIdx = 269;
                    section.data(232).dtTransOffset = 410;

                    ;% UAM_Flight_control_B.Merge_o
                    section.data(233).logicalSrcIdx = 270;
                    section.data(233).dtTransOffset = 411;

                    ;% UAM_Flight_control_B.Saturation_k
                    section.data(234).logicalSrcIdx = 272;
                    section.data(234).dtTransOffset = 414;

                    ;% UAM_Flight_control_B.Saturation1_k
                    section.data(235).logicalSrcIdx = 273;
                    section.data(235).dtTransOffset = 415;

                    ;% UAM_Flight_control_B.Saturation_n
                    section.data(236).logicalSrcIdx = 274;
                    section.data(236).dtTransOffset = 416;

                    ;% UAM_Flight_control_B.Saturation_m
                    section.data(237).logicalSrcIdx = 275;
                    section.data(237).dtTransOffset = 417;

                    ;% UAM_Flight_control_B.Saturation_m4
                    section.data(238).logicalSrcIdx = 276;
                    section.data(238).dtTransOffset = 418;

                    ;% UAM_Flight_control_B.Saturation_b
                    section.data(239).logicalSrcIdx = 277;
                    section.data(239).dtTransOffset = 419;

                    ;% UAM_Flight_control_B.Saturation_c
                    section.data(240).logicalSrcIdx = 278;
                    section.data(240).dtTransOffset = 420;

                    ;% UAM_Flight_control_B.ClimbRateSPMerge
                    section.data(241).logicalSrcIdx = 279;
                    section.data(241).dtTransOffset = 421;

                    ;% UAM_Flight_control_B.UnaryMinus
                    section.data(242).logicalSrcIdx = 280;
                    section.data(242).dtTransOffset = 422;

                    ;% UAM_Flight_control_B.Saturation_f
                    section.data(243).logicalSrcIdx = 281;
                    section.data(243).dtTransOffset = 423;

                    ;% UAM_Flight_control_B.UnaryMinus_a
                    section.data(244).logicalSrcIdx = 283;
                    section.data(244).dtTransOffset = 424;

                    ;% UAM_Flight_control_B.Saturation_p
                    section.data(245).logicalSrcIdx = 284;
                    section.data(245).dtTransOffset = 425;

                    ;% UAM_Flight_control_B.Merge2
                    section.data(246).logicalSrcIdx = 285;
                    section.data(246).dtTransOffset = 426;

                    ;% UAM_Flight_control_B.Gain_a
                    section.data(247).logicalSrcIdx = 286;
                    section.data(247).dtTransOffset = 427;

                    ;% UAM_Flight_control_B.RefRP
                    section.data(248).logicalSrcIdx = 287;
                    section.data(248).dtTransOffset = 430;

                    ;% UAM_Flight_control_B.Sum_n
                    section.data(249).logicalSrcIdx = 288;
                    section.data(249).dtTransOffset = 432;

                    ;% UAM_Flight_control_B.Sum_o
                    section.data(250).logicalSrcIdx = 289;
                    section.data(250).dtTransOffset = 433;

                    ;% UAM_Flight_control_B.Saturation5
                    section.data(251).logicalSrcIdx = 290;
                    section.data(251).dtTransOffset = 434;

                    ;% UAM_Flight_control_B.w_phi
                    section.data(252).logicalSrcIdx = 291;
                    section.data(252).dtTransOffset = 435;

                    ;% UAM_Flight_control_B.w_theta
                    section.data(253).logicalSrcIdx = 292;
                    section.data(253).dtTransOffset = 436;

                    ;% UAM_Flight_control_B.w_psi
                    section.data(254).logicalSrcIdx = 293;
                    section.data(254).dtTransOffset = 437;

                    ;% UAM_Flight_control_B.w_z
                    section.data(255).logicalSrcIdx = 294;
                    section.data(255).dtTransOffset = 438;

                    ;% UAM_Flight_control_B.In1
                    section.data(256).logicalSrcIdx = 295;
                    section.data(256).dtTransOffset = 439;

                    ;% UAM_Flight_control_B.Add_c
                    section.data(257).logicalSrcIdx = 296;
                    section.data(257).dtTransOffset = 440;

                    ;% UAM_Flight_control_B.Switch2
                    section.data(258).logicalSrcIdx = 297;
                    section.data(258).dtTransOffset = 441;

                    ;% UAM_Flight_control_B.Switch1
                    section.data(259).logicalSrcIdx = 298;
                    section.data(259).dtTransOffset = 442;

                    ;% UAM_Flight_control_B.Add_i
                    section.data(260).logicalSrcIdx = 299;
                    section.data(260).dtTransOffset = 443;

                    ;% UAM_Flight_control_B.Switch
                    section.data(261).logicalSrcIdx = 300;
                    section.data(261).dtTransOffset = 444;

                    ;% UAM_Flight_control_B.Saturation_kf
                    section.data(262).logicalSrcIdx = 301;
                    section.data(262).dtTransOffset = 445;

                    ;% UAM_Flight_control_B.Saturation1_ke
                    section.data(263).logicalSrcIdx = 302;
                    section.data(263).dtTransOffset = 446;

                    ;% UAM_Flight_control_B.Add_h
                    section.data(264).logicalSrcIdx = 303;
                    section.data(264).dtTransOffset = 447;

                    ;% UAM_Flight_control_B.Switch1_n
                    section.data(265).logicalSrcIdx = 304;
                    section.data(265).dtTransOffset = 448;

                    ;% UAM_Flight_control_B.Add_o
                    section.data(266).logicalSrcIdx = 305;
                    section.data(266).dtTransOffset = 449;

                    ;% UAM_Flight_control_B.Saturation_a
                    section.data(267).logicalSrcIdx = 306;
                    section.data(267).dtTransOffset = 450;

                    ;% UAM_Flight_control_B.Saturation_ke
                    section.data(268).logicalSrcIdx = 307;
                    section.data(268).dtTransOffset = 451;

                    ;% UAM_Flight_control_B.XRef
                    section.data(269).logicalSrcIdx = 308;
                    section.data(269).dtTransOffset = 452;

                    ;% UAM_Flight_control_B.YRef
                    section.data(270).logicalSrcIdx = 309;
                    section.data(270).dtTransOffset = 453;

                    ;% UAM_Flight_control_B.Gain_c
                    section.data(271).logicalSrcIdx = 310;
                    section.data(271).dtTransOffset = 454;

                    ;% UAM_Flight_control_B.UnitDelay
                    section.data(272).logicalSrcIdx = 311;
                    section.data(272).dtTransOffset = 455;

                    ;% UAM_Flight_control_B.Switch1_nh
                    section.data(273).logicalSrcIdx = 312;
                    section.data(273).dtTransOffset = 456;

                    ;% UAM_Flight_control_B.ProportionalGain
                    section.data(274).logicalSrcIdx = 313;
                    section.data(274).dtTransOffset = 457;

                    ;% UAM_Flight_control_B.Gain1_i
                    section.data(275).logicalSrcIdx = 314;
                    section.data(275).dtTransOffset = 458;

                    ;% UAM_Flight_control_B.Sum3
                    section.data(276).logicalSrcIdx = 315;
                    section.data(276).dtTransOffset = 459;

                    ;% UAM_Flight_control_B.Product
                    section.data(277).logicalSrcIdx = 316;
                    section.data(277).dtTransOffset = 460;

                    ;% UAM_Flight_control_B.y
                    section.data(278).logicalSrcIdx = 317;
                    section.data(278).dtTransOffset = 461;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_cv2z
                    section.data(279).logicalSrcIdx = 318;
                    section.data(279).dtTransOffset = 462;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_ezp
                    section.data(280).logicalSrcIdx = 319;
                    section.data(280).dtTransOffset = 463;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_dec
                    section.data(281).logicalSrcIdx = 320;
                    section.data(281).dtTransOffset = 464;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_gbt
                    section.data(282).logicalSrcIdx = 321;
                    section.data(282).dtTransOffset = 465;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_nw2
                    section.data(283).logicalSrcIdx = 322;
                    section.data(283).dtTransOffset = 466;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_i0g
                    section.data(284).logicalSrcIdx = 323;
                    section.data(284).dtTransOffset = 467;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_dgzi
                    section.data(285).logicalSrcIdx = 324;
                    section.data(285).dtTransOffset = 468;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_ae0
                    section.data(286).logicalSrcIdx = 325;
                    section.data(286).dtTransOffset = 469;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_bjh
                    section.data(287).logicalSrcIdx = 326;
                    section.data(287).dtTransOffset = 470;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_jjd
                    section.data(288).logicalSrcIdx = 327;
                    section.data(288).dtTransOffset = 471;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_n2x4
                    section.data(289).logicalSrcIdx = 328;
                    section.data(289).dtTransOffset = 472;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_gx0x
                    section.data(290).logicalSrcIdx = 329;
                    section.data(290).dtTransOffset = 473;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_adlp
                    section.data(291).logicalSrcIdx = 330;
                    section.data(291).dtTransOffset = 474;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_bbr4
                    section.data(292).logicalSrcIdx = 331;
                    section.data(292).dtTransOffset = 475;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_pyg
                    section.data(293).logicalSrcIdx = 332;
                    section.data(293).dtTransOffset = 476;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_pdsb
                    section.data(294).logicalSrcIdx = 333;
                    section.data(294).dtTransOffset = 477;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_fsn
                    section.data(295).logicalSrcIdx = 334;
                    section.data(295).dtTransOffset = 478;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_by1n
                    section.data(296).logicalSrcIdx = 335;
                    section.data(296).dtTransOffset = 479;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_cr0
                    section.data(297).logicalSrcIdx = 336;
                    section.data(297).dtTransOffset = 480;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_duzz
                    section.data(298).logicalSrcIdx = 337;
                    section.data(298).dtTransOffset = 481;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_b55m
                    section.data(299).logicalSrcIdx = 338;
                    section.data(299).dtTransOffset = 482;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_awya
                    section.data(300).logicalSrcIdx = 339;
                    section.data(300).dtTransOffset = 486;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_jx3i
                    section.data(301).logicalSrcIdx = 340;
                    section.data(301).dtTransOffset = 487;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_cvbt
                    section.data(302).logicalSrcIdx = 341;
                    section.data(302).dtTransOffset = 488;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_fp5m
                    section.data(303).logicalSrcIdx = 342;
                    section.data(303).dtTransOffset = 504;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_oniv
                    section.data(304).logicalSrcIdx = 344;
                    section.data(304).dtTransOffset = 507;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_daxi
                    section.data(305).logicalSrcIdx = 345;
                    section.data(305).dtTransOffset = 508;

                    ;% UAM_Flight_control_B.VectorConcatenate_c
                    section.data(306).logicalSrcIdx = 346;
                    section.data(306).dtTransOffset = 509;

                    ;% UAM_Flight_control_B.Constant
                    section.data(307).logicalSrcIdx = 347;
                    section.data(307).dtTransOffset = 515;

                    ;% UAM_Flight_control_B.TmpSignalConversionAtMatrixMult
                    section.data(308).logicalSrcIdx = 348;
                    section.data(308).dtTransOffset = 531;

                    ;% UAM_Flight_control_B.m_l
                    section.data(309).logicalSrcIdx = 349;
                    section.data(309).dtTransOffset = 535;

                    ;% UAM_Flight_control_B.TmpBufferAtConstant4Outport1_k
                    section.data(310).logicalSrcIdx = 350;
                    section.data(310).dtTransOffset = 539;

                    ;% UAM_Flight_control_B.m_out
                    section.data(311).logicalSrcIdx = 351;
                    section.data(311).dtTransOffset = 540;

                    ;% UAM_Flight_control_B.dA_n
                    section.data(312).logicalSrcIdx = 352;
                    section.data(312).dtTransOffset = 544;

                    ;% UAM_Flight_control_B.dE_a
                    section.data(313).logicalSrcIdx = 353;
                    section.data(313).dtTransOffset = 545;

                    ;% UAM_Flight_control_B.dR_g
                    section.data(314).logicalSrcIdx = 354;
                    section.data(314).dtTransOffset = 546;

                    ;% UAM_Flight_control_B.dT_i
                    section.data(315).logicalSrcIdx = 355;
                    section.data(315).dtTransOffset = 547;

                    ;% UAM_Flight_control_B.MatrixMultiply
                    section.data(316).logicalSrcIdx = 356;
                    section.data(316).dtTransOffset = 548;

                    ;% UAM_Flight_control_B.Saturation2_n
                    section.data(317).logicalSrcIdx = 357;
                    section.data(317).dtTransOffset = 550;

            nTotData = nTotData + section.nData;
            sigMap.sections(10) = section;
            clear section

            section.nData     = 55;
            section.data(55)  = dumData; %prealloc

                    ;% UAM_Flight_control_B.target_roll
                    section.data(1).logicalSrcIdx = 358;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_B.target_pitch
                    section.data(2).logicalSrcIdx = 359;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_B.target_yaw
                    section.data(3).logicalSrcIdx = 360;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_B.target_alt
                    section.data(4).logicalSrcIdx = 361;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_B.dist_n
                    section.data(5).logicalSrcIdx = 362;
                    section.data(5).dtTransOffset = 4;

                    ;% UAM_Flight_control_B.dist_e
                    section.data(6).logicalSrcIdx = 363;
                    section.data(6).dtTransOffset = 5;

                    ;% UAM_Flight_control_B.dist_d
                    section.data(7).logicalSrcIdx = 364;
                    section.data(7).dtTransOffset = 6;

                    ;% UAM_Flight_control_B.roll_rate
                    section.data(8).logicalSrcIdx = 365;
                    section.data(8).dtTransOffset = 7;

                    ;% UAM_Flight_control_B.pitch_rate
                    section.data(9).logicalSrcIdx = 366;
                    section.data(9).dtTransOffset = 8;

                    ;% UAM_Flight_control_B.yaw_rate
                    section.data(10).logicalSrcIdx = 367;
                    section.data(10).dtTransOffset = 9;

                    ;% UAM_Flight_control_B.target_x
                    section.data(11).logicalSrcIdx = 368;
                    section.data(11).dtTransOffset = 10;

                    ;% UAM_Flight_control_B.target_y
                    section.data(12).logicalSrcIdx = 369;
                    section.data(12).dtTransOffset = 11;

                    ;% UAM_Flight_control_B.target_z
                    section.data(13).logicalSrcIdx = 370;
                    section.data(13).dtTransOffset = 12;

                    ;% UAM_Flight_control_B.target_x_a
                    section.data(14).logicalSrcIdx = 371;
                    section.data(14).dtTransOffset = 13;

                    ;% UAM_Flight_control_B.target_y_p
                    section.data(15).logicalSrcIdx = 372;
                    section.data(15).dtTransOffset = 14;

                    ;% UAM_Flight_control_B.target_z_m
                    section.data(16).logicalSrcIdx = 373;
                    section.data(16).dtTransOffset = 15;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ba
                    section.data(17).logicalSrcIdx = 374;
                    section.data(17).dtTransOffset = 16;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ed
                    section.data(18).logicalSrcIdx = 375;
                    section.data(18).dtTransOffset = 17;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_nl
                    section.data(19).logicalSrcIdx = 376;
                    section.data(19).dtTransOffset = 18;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_k
                    section.data(20).logicalSrcIdx = 377;
                    section.data(20).dtTransOffset = 19;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_m
                    section.data(21).logicalSrcIdx = 378;
                    section.data(21).dtTransOffset = 20;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ps
                    section.data(22).logicalSrcIdx = 379;
                    section.data(22).dtTransOffset = 21;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_aj
                    section.data(23).logicalSrcIdx = 380;
                    section.data(23).dtTransOffset = 22;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_h
                    section.data(24).logicalSrcIdx = 381;
                    section.data(24).dtTransOffset = 23;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_pg
                    section.data(25).logicalSrcIdx = 382;
                    section.data(25).dtTransOffset = 24;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_mq
                    section.data(26).logicalSrcIdx = 383;
                    section.data(26).dtTransOffset = 25;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ke
                    section.data(27).logicalSrcIdx = 384;
                    section.data(27).dtTransOffset = 26;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ah
                    section.data(28).logicalSrcIdx = 385;
                    section.data(28).dtTransOffset = 27;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_e1
                    section.data(29).logicalSrcIdx = 386;
                    section.data(29).dtTransOffset = 28;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_baw
                    section.data(30).logicalSrcIdx = 387;
                    section.data(30).dtTransOffset = 29;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_edg
                    section.data(31).logicalSrcIdx = 388;
                    section.data(31).dtTransOffset = 30;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_nly
                    section.data(32).logicalSrcIdx = 389;
                    section.data(32).dtTransOffset = 31;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_kb
                    section.data(33).logicalSrcIdx = 390;
                    section.data(33).dtTransOffset = 32;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_me
                    section.data(34).logicalSrcIdx = 391;
                    section.data(34).dtTransOffset = 33;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_ps2
                    section.data(35).logicalSrcIdx = 392;
                    section.data(35).dtTransOffset = 34;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_ajj
                    section.data(36).logicalSrcIdx = 393;
                    section.data(36).dtTransOffset = 35;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_hw
                    section.data(37).logicalSrcIdx = 394;
                    section.data(37).dtTransOffset = 36;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_pgb
                    section.data(38).logicalSrcIdx = 395;
                    section.data(38).dtTransOffset = 37;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_mqv
                    section.data(39).logicalSrcIdx = 396;
                    section.data(39).dtTransOffset = 38;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_kew
                    section.data(40).logicalSrcIdx = 397;
                    section.data(40).dtTransOffset = 39;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_ahl
                    section.data(41).logicalSrcIdx = 398;
                    section.data(41).dtTransOffset = 40;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_e1u
                    section.data(42).logicalSrcIdx = 399;
                    section.data(42).dtTransOffset = 41;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_bawm
                    section.data(43).logicalSrcIdx = 400;
                    section.data(43).dtTransOffset = 42;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_edgh
                    section.data(44).logicalSrcIdx = 401;
                    section.data(44).dtTransOffset = 43;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_nlya
                    section.data(45).logicalSrcIdx = 402;
                    section.data(45).dtTransOffset = 44;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_kbh
                    section.data(46).logicalSrcIdx = 403;
                    section.data(46).dtTransOffset = 45;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_mey
                    section.data(47).logicalSrcIdx = 404;
                    section.data(47).dtTransOffset = 46;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_ps2n
                    section.data(48).logicalSrcIdx = 405;
                    section.data(48).dtTransOffset = 47;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_ajjw
                    section.data(49).logicalSrcIdx = 406;
                    section.data(49).dtTransOffset = 48;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_hwn
                    section.data(50).logicalSrcIdx = 407;
                    section.data(50).dtTransOffset = 49;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_pgbn
                    section.data(51).logicalSrcIdx = 408;
                    section.data(51).dtTransOffset = 50;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_mqvj
                    section.data(52).logicalSrcIdx = 409;
                    section.data(52).dtTransOffset = 51;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_kewq
                    section.data(53).logicalSrcIdx = 410;
                    section.data(53).dtTransOffset = 52;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_ahl1
                    section.data(54).logicalSrcIdx = 411;
                    section.data(54).dtTransOffset = 53;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_e1ub
                    section.data(55).logicalSrcIdx = 412;
                    section.data(55).dtTransOffset = 54;

            nTotData = nTotData + section.nData;
            sigMap.sections(11) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% UAM_Flight_control_B.FlightMode
                    section.data(1).logicalSrcIdx = 413;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_B.Hover_p
                    section.data(2).logicalSrcIdx = 414;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_B.flightMode
                    section.data(3).logicalSrcIdx = 415;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_B.Constant2
                    section.data(4).logicalSrcIdx = 416;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_B.FlightMode_o
                    section.data(5).logicalSrcIdx = 417;
                    section.data(5).dtTransOffset = 4;

                    ;% UAM_Flight_control_B.Hover_i
                    section.data(6).logicalSrcIdx = 418;
                    section.data(6).dtTransOffset = 5;

                    ;% UAM_Flight_control_B.flightMode_c
                    section.data(7).logicalSrcIdx = 419;
                    section.data(7).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            sigMap.sections(12) = section;
            clear section

            section.nData     = 20;
            section.data(20)  = dumData; %prealloc

                    ;% UAM_Flight_control_B.voltage
                    section.data(1).logicalSrcIdx = 421;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_B.current
                    section.data(2).logicalSrcIdx = 422;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_B.soc
                    section.data(3).logicalSrcIdx = 423;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_B.temperature
                    section.data(4).logicalSrcIdx = 424;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_B.soh
                    section.data(5).logicalSrcIdx = 425;
                    section.data(5).dtTransOffset = 4;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_l
                    section.data(6).logicalSrcIdx = 426;
                    section.data(6).dtTransOffset = 5;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_bk
                    section.data(7).logicalSrcIdx = 427;
                    section.data(7).dtTransOffset = 6;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ir
                    section.data(8).logicalSrcIdx = 428;
                    section.data(8).dtTransOffset = 7;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ex
                    section.data(9).logicalSrcIdx = 429;
                    section.data(9).dtTransOffset = 8;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ou
                    section.data(10).logicalSrcIdx = 430;
                    section.data(10).dtTransOffset = 9;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_l5
                    section.data(11).logicalSrcIdx = 431;
                    section.data(11).dtTransOffset = 10;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_bkn
                    section.data(12).logicalSrcIdx = 432;
                    section.data(12).dtTransOffset = 11;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_irm
                    section.data(13).logicalSrcIdx = 433;
                    section.data(13).dtTransOffset = 12;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_exu
                    section.data(14).logicalSrcIdx = 434;
                    section.data(14).dtTransOffset = 13;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_ouu
                    section.data(15).logicalSrcIdx = 435;
                    section.data(15).dtTransOffset = 14;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_l5c
                    section.data(16).logicalSrcIdx = 436;
                    section.data(16).dtTransOffset = 15;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_bkn5
                    section.data(17).logicalSrcIdx = 437;
                    section.data(17).dtTransOffset = 16;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_irme
                    section.data(18).logicalSrcIdx = 438;
                    section.data(18).dtTransOffset = 17;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_exub
                    section.data(19).logicalSrcIdx = 439;
                    section.data(19).dtTransOffset = 18;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_ouuy
                    section.data(20).logicalSrcIdx = 440;
                    section.data(20).dtTransOffset = 19;

            nTotData = nTotData + section.nData;
            sigMap.sections(13) = section;
            clear section

            section.nData     = 23;
            section.data(23)  = dumData; %prealloc

                    ;% UAM_Flight_control_B.mode
                    section.data(1).logicalSrcIdx = 441;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_B.gps_num_sv
                    section.data(2).logicalSrcIdx = 442;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_B.gcs_link
                    section.data(3).logicalSrcIdx = 443;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_B.rc_link
                    section.data(4).logicalSrcIdx = 444;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_B.flight_mode
                    section.data(5).logicalSrcIdx = 445;
                    section.data(5).dtTransOffset = 4;

                    ;% UAM_Flight_control_B.Status
                    section.data(6).logicalSrcIdx = 446;
                    section.data(6).dtTransOffset = 5;

                    ;% UAM_Flight_control_B.mode_j
                    section.data(7).logicalSrcIdx = 447;
                    section.data(7).dtTransOffset = 6;

                    ;% UAM_Flight_control_B.Status_e
                    section.data(8).logicalSrcIdx = 448;
                    section.data(8).dtTransOffset = 7;

                    ;% UAM_Flight_control_B.WaypointFollower_o4
                    section.data(9).logicalSrcIdx = 449;
                    section.data(9).dtTransOffset = 8;

                    ;% UAM_Flight_control_B.WaypointFollower_o4_h
                    section.data(10).logicalSrcIdx = 450;
                    section.data(10).dtTransOffset = 9;

                    ;% UAM_Flight_control_B.WaypointFollower_o5
                    section.data(11).logicalSrcIdx = 451;
                    section.data(11).dtTransOffset = 10;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_dq
                    section.data(12).logicalSrcIdx = 452;
                    section.data(12).dtTransOffset = 11;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_k5
                    section.data(13).logicalSrcIdx = 453;
                    section.data(13).dtTransOffset = 12;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_od
                    section.data(14).logicalSrcIdx = 454;
                    section.data(14).dtTransOffset = 13;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_a2
                    section.data(15).logicalSrcIdx = 455;
                    section.data(15).dtTransOffset = 14;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_dq0
                    section.data(16).logicalSrcIdx = 456;
                    section.data(16).dtTransOffset = 15;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_k55
                    section.data(17).logicalSrcIdx = 457;
                    section.data(17).dtTransOffset = 16;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_odd
                    section.data(18).logicalSrcIdx = 458;
                    section.data(18).dtTransOffset = 17;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_a2g
                    section.data(19).logicalSrcIdx = 459;
                    section.data(19).dtTransOffset = 18;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_dq0y
                    section.data(20).logicalSrcIdx = 460;
                    section.data(20).dtTransOffset = 19;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_k55z
                    section.data(21).logicalSrcIdx = 461;
                    section.data(21).dtTransOffset = 20;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_odds
                    section.data(22).logicalSrcIdx = 462;
                    section.data(22).dtTransOffset = 21;

                    ;% UAM_Flight_control_B.TmpBufferAtActuator_BusCre_a2gj
                    section.data(23).logicalSrcIdx = 463;
                    section.data(23).dtTransOffset = 22;

            nTotData = nTotData + section.nData;
            sigMap.sections(14) = section;
            clear section

            section.nData     = 15;
            section.data(15)  = dumData; %prealloc

                    ;% UAM_Flight_control_B.DataTypeConversion
                    section.data(1).logicalSrcIdx = 464;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_B.Compare
                    section.data(2).logicalSrcIdx = 465;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_B.Constant_n
                    section.data(3).logicalSrcIdx = 466;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_B.valid
                    section.data(4).logicalSrcIdx = 467;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_B.XYZ_Valid
                    section.data(5).logicalSrcIdx = 468;
                    section.data(5).dtTransOffset = 4;

                    ;% UAM_Flight_control_B.AND1
                    section.data(6).logicalSrcIdx = 469;
                    section.data(6).dtTransOffset = 5;

                    ;% UAM_Flight_control_B.OR1
                    section.data(7).logicalSrcIdx = 470;
                    section.data(7).dtTransOffset = 6;

                    ;% UAM_Flight_control_B.XYZ_nan
                    section.data(8).logicalSrcIdx = 471;
                    section.data(8).dtTransOffset = 7;

                    ;% UAM_Flight_control_B.OR
                    section.data(9).logicalSrcIdx = 472;
                    section.data(9).dtTransOffset = 8;

                    ;% UAM_Flight_control_B.AND
                    section.data(10).logicalSrcIdx = 473;
                    section.data(10).dtTransOffset = 9;

                    ;% UAM_Flight_control_B.Compare_m
                    section.data(11).logicalSrcIdx = 474;
                    section.data(11).dtTransOffset = 10;

                    ;% UAM_Flight_control_B.FixPtRelationalOperator
                    section.data(12).logicalSrcIdx = 475;
                    section.data(12).dtTransOffset = 11;

                    ;% UAM_Flight_control_B.FixPtRelationalOperator_d
                    section.data(13).logicalSrcIdx = 476;
                    section.data(13).dtTransOffset = 12;

                    ;% UAM_Flight_control_B.OR_j
                    section.data(14).logicalSrcIdx = 477;
                    section.data(14).dtTransOffset = 13;

                    ;% UAM_Flight_control_B.OR_e
                    section.data(15).logicalSrcIdx = 478;
                    section.data(15).dtTransOffset = 14;

            nTotData = nTotData + section.nData;
            sigMap.sections(15) = section;
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
        nTotSects     = 52;
        sectIdxOffset = 15;

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

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.obj_b
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_DW.obj_i
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.obj_p
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.obj_c
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.obj_h
                    section.data(1).logicalSrcIdx = 5;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.obj_o
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_DW.obj_a
                    section.data(2).logicalSrcIdx = 7;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.UnitDelay_3_DSTATE
                    section.data(1).logicalSrcIdx = 8;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_DW.UnitDelay_2_DSTATE
                    section.data(2).logicalSrcIdx = 9;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.UnitDelay1_7_DSTATE
                    section.data(1).logicalSrcIdx = 10;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.UnitDelay_6_DSTATE
                    section.data(1).logicalSrcIdx = 11;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_DW.UnitDelay_6_DSTATE_g
                    section.data(2).logicalSrcIdx = 12;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_DW.UnitDelay_6_DSTATE_b
                    section.data(3).logicalSrcIdx = 13;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(9) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.RateTransition1_13_Buffer
                    section.data(1).logicalSrcIdx = 14;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(10) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.UnitDelay_5_DSTATE
                    section.data(1).logicalSrcIdx = 15;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_DW.UnitDelay_5_DSTATE_i
                    section.data(2).logicalSrcIdx = 16;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_DW.UnitDelay_5_DSTATE_h
                    section.data(3).logicalSrcIdx = 17;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(11) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.UnitDelay_7_DSTATE
                    section.data(1).logicalSrcIdx = 18;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_DW.UnitDelay_7_DSTATE_g
                    section.data(2).logicalSrcIdx = 19;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_DW.UnitDelay_7_DSTATE_b
                    section.data(3).logicalSrcIdx = 20;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(12) = section;
            clear section

            section.nData     = 149;
            section.data(149)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.UnitDelay2_DSTATE
                    section.data(1).logicalSrcIdx = 21;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_DW.UnitDelay3_DSTATE
                    section.data(2).logicalSrcIdx = 22;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_DW.UnitDelay4_DSTATE
                    section.data(3).logicalSrcIdx = 23;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_DW.UnitDelay_DSTATE_m
                    section.data(4).logicalSrcIdx = 27;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_DW.UnitDelay1_9_DSTATE
                    section.data(5).logicalSrcIdx = 28;
                    section.data(5).dtTransOffset = 7;

                    ;% UAM_Flight_control_DW.UnitDelay1_8_DSTATE
                    section.data(6).logicalSrcIdx = 29;
                    section.data(6).dtTransOffset = 10;

                    ;% UAM_Flight_control_DW.UnitDelay1_6_DSTATE
                    section.data(7).logicalSrcIdx = 30;
                    section.data(7).dtTransOffset = 20;

                    ;% UAM_Flight_control_DW.UnitDelay1_5_DSTATE
                    section.data(8).logicalSrcIdx = 31;
                    section.data(8).dtTransOffset = 21;

                    ;% UAM_Flight_control_DW.UnitDelay1_4_DSTATE
                    section.data(9).logicalSrcIdx = 32;
                    section.data(9).dtTransOffset = 24;

                    ;% UAM_Flight_control_DW.UnitDelay1_3_DSTATE
                    section.data(10).logicalSrcIdx = 33;
                    section.data(10).dtTransOffset = 27;

                    ;% UAM_Flight_control_DW.UnitDelay1_2_DSTATE
                    section.data(11).logicalSrcIdx = 34;
                    section.data(11).dtTransOffset = 30;

                    ;% UAM_Flight_control_DW.UnitDelay1_1_DSTATE
                    section.data(12).logicalSrcIdx = 35;
                    section.data(12).dtTransOffset = 33;

                    ;% UAM_Flight_control_DW.UnitDelay2_DSTATE_l
                    section.data(13).logicalSrcIdx = 36;
                    section.data(13).dtTransOffset = 37;

                    ;% UAM_Flight_control_DW.UnitDelay1_10_DSTATE
                    section.data(14).logicalSrcIdx = 37;
                    section.data(14).dtTransOffset = 38;

                    ;% UAM_Flight_control_DW.UnitDelay_1_DSTATE
                    section.data(15).logicalSrcIdx = 38;
                    section.data(15).dtTransOffset = 39;

                    ;% UAM_Flight_control_DW.UnitDelay_2_DSTATE_g
                    section.data(16).logicalSrcIdx = 39;
                    section.data(16).dtTransOffset = 40;

                    ;% UAM_Flight_control_DW.UnitDelay_3_DSTATE_i
                    section.data(17).logicalSrcIdx = 40;
                    section.data(17).dtTransOffset = 41;

                    ;% UAM_Flight_control_DW.UnitDelay_4_DSTATE
                    section.data(18).logicalSrcIdx = 41;
                    section.data(18).dtTransOffset = 42;

                    ;% UAM_Flight_control_DW.UnitDelay_1_DSTATE_n
                    section.data(19).logicalSrcIdx = 42;
                    section.data(19).dtTransOffset = 43;

                    ;% UAM_Flight_control_DW.UnitDelay_2_DSTATE_e
                    section.data(20).logicalSrcIdx = 43;
                    section.data(20).dtTransOffset = 44;

                    ;% UAM_Flight_control_DW.UnitDelay_3_DSTATE_n
                    section.data(21).logicalSrcIdx = 44;
                    section.data(21).dtTransOffset = 45;

                    ;% UAM_Flight_control_DW.UnitDelay_4_DSTATE_h
                    section.data(22).logicalSrcIdx = 45;
                    section.data(22).dtTransOffset = 46;

                    ;% UAM_Flight_control_DW.Filter_DSTATE
                    section.data(23).logicalSrcIdx = 50;
                    section.data(23).dtTransOffset = 47;

                    ;% UAM_Flight_control_DW.Integrator_DSTATE
                    section.data(24).logicalSrcIdx = 51;
                    section.data(24).dtTransOffset = 48;

                    ;% UAM_Flight_control_DW.Filter_DSTATE_l
                    section.data(25).logicalSrcIdx = 52;
                    section.data(25).dtTransOffset = 49;

                    ;% UAM_Flight_control_DW.Filter_DSTATE_n
                    section.data(26).logicalSrcIdx = 53;
                    section.data(26).dtTransOffset = 50;

                    ;% UAM_Flight_control_DW.Integrator_DSTATE_l
                    section.data(27).logicalSrcIdx = 54;
                    section.data(27).dtTransOffset = 51;

                    ;% UAM_Flight_control_DW.Filter_DSTATE_e
                    section.data(28).logicalSrcIdx = 55;
                    section.data(28).dtTransOffset = 52;

                    ;% UAM_Flight_control_DW.Integrator_DSTATE_i
                    section.data(29).logicalSrcIdx = 56;
                    section.data(29).dtTransOffset = 53;

                    ;% UAM_Flight_control_DW.Filter_DSTATE_c
                    section.data(30).logicalSrcIdx = 57;
                    section.data(30).dtTransOffset = 54;

                    ;% UAM_Flight_control_DW.Integrator_DSTATE_c
                    section.data(31).logicalSrcIdx = 58;
                    section.data(31).dtTransOffset = 55;

                    ;% UAM_Flight_control_DW.Filter_DSTATE_p
                    section.data(32).logicalSrcIdx = 59;
                    section.data(32).dtTransOffset = 56;

                    ;% UAM_Flight_control_DW.Integrator_DSTATE_o
                    section.data(33).logicalSrcIdx = 60;
                    section.data(33).dtTransOffset = 57;

                    ;% UAM_Flight_control_DW.Filter_DSTATE_lh
                    section.data(34).logicalSrcIdx = 61;
                    section.data(34).dtTransOffset = 58;

                    ;% UAM_Flight_control_DW.Integrator_DSTATE_g
                    section.data(35).logicalSrcIdx = 62;
                    section.data(35).dtTransOffset = 59;

                    ;% UAM_Flight_control_DW.Filter_DSTATE_cn
                    section.data(36).logicalSrcIdx = 63;
                    section.data(36).dtTransOffset = 60;

                    ;% UAM_Flight_control_DW.Integrator_DSTATE_go
                    section.data(37).logicalSrcIdx = 64;
                    section.data(37).dtTransOffset = 61;

                    ;% UAM_Flight_control_DW.Integrator_DSTATE_m
                    section.data(38).logicalSrcIdx = 65;
                    section.data(38).dtTransOffset = 62;

                    ;% UAM_Flight_control_DW.Filter_DSTATE_g
                    section.data(39).logicalSrcIdx = 66;
                    section.data(39).dtTransOffset = 63;

                    ;% UAM_Flight_control_DW.Filter_DSTATE_no
                    section.data(40).logicalSrcIdx = 67;
                    section.data(40).dtTransOffset = 64;

                    ;% UAM_Flight_control_DW.Integrator_DSTATE_j
                    section.data(41).logicalSrcIdx = 68;
                    section.data(41).dtTransOffset = 65;

                    ;% UAM_Flight_control_DW.Integrator_DSTATE_p
                    section.data(42).logicalSrcIdx = 69;
                    section.data(42).dtTransOffset = 66;

                    ;% UAM_Flight_control_DW.Filter_DSTATE_d
                    section.data(43).logicalSrcIdx = 70;
                    section.data(43).dtTransOffset = 67;

                    ;% UAM_Flight_control_DW.Integrator_DSTATE_a
                    section.data(44).logicalSrcIdx = 71;
                    section.data(44).dtTransOffset = 68;

                    ;% UAM_Flight_control_DW.Filter_DSTATE_k
                    section.data(45).logicalSrcIdx = 72;
                    section.data(45).dtTransOffset = 69;

                    ;% UAM_Flight_control_DW.Integrator_DSTATE_jq
                    section.data(46).logicalSrcIdx = 73;
                    section.data(46).dtTransOffset = 70;

                    ;% UAM_Flight_control_DW.Filter_DSTATE_h
                    section.data(47).logicalSrcIdx = 74;
                    section.data(47).dtTransOffset = 71;

                    ;% UAM_Flight_control_DW.Integrator_DSTATE_aq
                    section.data(48).logicalSrcIdx = 75;
                    section.data(48).dtTransOffset = 72;

                    ;% UAM_Flight_control_DW.Filter_DSTATE_f
                    section.data(49).logicalSrcIdx = 76;
                    section.data(49).dtTransOffset = 73;

                    ;% UAM_Flight_control_DW.Filter_DSTATE_p5
                    section.data(50).logicalSrcIdx = 77;
                    section.data(50).dtTransOffset = 74;

                    ;% UAM_Flight_control_DW.Integrator_DSTATE_h
                    section.data(51).logicalSrcIdx = 78;
                    section.data(51).dtTransOffset = 75;

                    ;% UAM_Flight_control_DW.Integrator_DSTATE_n
                    section.data(52).logicalSrcIdx = 79;
                    section.data(52).dtTransOffset = 76;

                    ;% UAM_Flight_control_DW.Filter_DSTATE_f5
                    section.data(53).logicalSrcIdx = 80;
                    section.data(53).dtTransOffset = 77;

                    ;% UAM_Flight_control_DW.Filter_DSTATE_h0
                    section.data(54).logicalSrcIdx = 81;
                    section.data(54).dtTransOffset = 78;

                    ;% UAM_Flight_control_DW.Integrator_DSTATE_ne
                    section.data(55).logicalSrcIdx = 82;
                    section.data(55).dtTransOffset = 79;

                    ;% UAM_Flight_control_DW.UnitDelay1_DSTATE_l
                    section.data(56).logicalSrcIdx = 83;
                    section.data(56).dtTransOffset = 80;

                    ;% UAM_Flight_control_DW.Integrator_DSTATE_nj
                    section.data(57).logicalSrcIdx = 84;
                    section.data(57).dtTransOffset = 81;

                    ;% UAM_Flight_control_DW.Filter_DSTATE_c5
                    section.data(58).logicalSrcIdx = 85;
                    section.data(58).dtTransOffset = 82;

                    ;% UAM_Flight_control_DW.Integrator_DSTATE_jv
                    section.data(59).logicalSrcIdx = 86;
                    section.data(59).dtTransOffset = 83;

                    ;% UAM_Flight_control_DW.Filter_DSTATE_nj
                    section.data(60).logicalSrcIdx = 87;
                    section.data(60).dtTransOffset = 84;

                    ;% UAM_Flight_control_DW.Integrator_DSTATE_mg
                    section.data(61).logicalSrcIdx = 88;
                    section.data(61).dtTransOffset = 85;

                    ;% UAM_Flight_control_DW.UnitDelay_DSTATE_i
                    section.data(62).logicalSrcIdx = 89;
                    section.data(62).dtTransOffset = 86;

                    ;% UAM_Flight_control_DW.UnitDelay1_DSTATE_p
                    section.data(63).logicalSrcIdx = 90;
                    section.data(63).dtTransOffset = 87;

                    ;% UAM_Flight_control_DW.Integrator_DSTATE_f
                    section.data(64).logicalSrcIdx = 91;
                    section.data(64).dtTransOffset = 88;

                    ;% UAM_Flight_control_DW.Filter_DSTATE_m
                    section.data(65).logicalSrcIdx = 92;
                    section.data(65).dtTransOffset = 89;

                    ;% UAM_Flight_control_DW.Integrator_DSTATE_j3
                    section.data(66).logicalSrcIdx = 93;
                    section.data(66).dtTransOffset = 90;

                    ;% UAM_Flight_control_DW.Filter_DSTATE_a
                    section.data(67).logicalSrcIdx = 94;
                    section.data(67).dtTransOffset = 91;

                    ;% UAM_Flight_control_DW.UnitDelay_DSTATE_e
                    section.data(68).logicalSrcIdx = 95;
                    section.data(68).dtTransOffset = 92;

                    ;% UAM_Flight_control_DW.Integrator_DSTATE_a2
                    section.data(69).logicalSrcIdx = 96;
                    section.data(69).dtTransOffset = 93;

                    ;% UAM_Flight_control_DW.Filter_DSTATE_fz
                    section.data(70).logicalSrcIdx = 97;
                    section.data(70).dtTransOffset = 94;

                    ;% UAM_Flight_control_DW.UnitDelay_DSTATE_g
                    section.data(71).logicalSrcIdx = 98;
                    section.data(71).dtTransOffset = 95;

                    ;% UAM_Flight_control_DW.Integrator_DSTATE_pq
                    section.data(72).logicalSrcIdx = 99;
                    section.data(72).dtTransOffset = 96;

                    ;% UAM_Flight_control_DW.Filter_DSTATE_px
                    section.data(73).logicalSrcIdx = 100;
                    section.data(73).dtTransOffset = 97;

                    ;% UAM_Flight_control_DW.RateTransition1_1_Buffer
                    section.data(74).logicalSrcIdx = 101;
                    section.data(74).dtTransOffset = 98;

                    ;% UAM_Flight_control_DW.RateTransition1_17_Buffer
                    section.data(75).logicalSrcIdx = 102;
                    section.data(75).dtTransOffset = 99;

                    ;% UAM_Flight_control_DW.y
                    section.data(76).logicalSrcIdx = 103;
                    section.data(76).dtTransOffset = 102;

                    ;% UAM_Flight_control_DW.h_ref
                    section.data(77).logicalSrcIdx = 104;
                    section.data(77).dtTransOffset = 103;

                    ;% UAM_Flight_control_DW.last_z
                    section.data(78).logicalSrcIdx = 105;
                    section.data(78).dtTransOffset = 104;

                    ;% UAM_Flight_control_DW.p0_Pa
                    section.data(79).logicalSrcIdx = 106;
                    section.data(79).dtTransOffset = 105;

                    ;% UAM_Flight_control_DW.stored_lat
                    section.data(80).logicalSrcIdx = 107;
                    section.data(80).dtTransOffset = 106;

                    ;% UAM_Flight_control_DW.stored_lon
                    section.data(81).logicalSrcIdx = 108;
                    section.data(81).dtTransOffset = 107;

                    ;% UAM_Flight_control_DW.stored_alt
                    section.data(82).logicalSrcIdx = 109;
                    section.data(82).dtTransOffset = 108;

                    ;% UAM_Flight_control_DW.quat
                    section.data(83).logicalSrcIdx = 110;
                    section.data(83).dtTransOffset = 109;

                    ;% UAM_Flight_control_DW.vel
                    section.data(84).logicalSrcIdx = 111;
                    section.data(84).dtTransOffset = 113;

                    ;% UAM_Flight_control_DW.pos
                    section.data(85).logicalSrcIdx = 112;
                    section.data(85).dtTransOffset = 116;

                    ;% UAM_Flight_control_DW.gyro_bias
                    section.data(86).logicalSrcIdx = 113;
                    section.data(86).dtTransOffset = 119;

                    ;% UAM_Flight_control_DW.accel_bias
                    section.data(87).logicalSrcIdx = 114;
                    section.data(87).dtTransOffset = 122;

                    ;% UAM_Flight_control_DW.wind_vel
                    section.data(88).logicalSrcIdx = 115;
                    section.data(88).dtTransOffset = 125;

                    ;% UAM_Flight_control_DW.terrain
                    section.data(89).logicalSrcIdx = 116;
                    section.data(89).dtTransOffset = 127;

                    ;% UAM_Flight_control_DW.Ps
                    section.data(90).logicalSrcIdx = 117;
                    section.data(90).dtTransOffset = 128;

                    ;% UAM_Flight_control_DW.mag_I
                    section.data(91).logicalSrcIdx = 118;
                    section.data(91).dtTransOffset = 704;

                    ;% UAM_Flight_control_DW.mag_B
                    section.data(92).logicalSrcIdx = 119;
                    section.data(92).dtTransOffset = 707;

                    ;% UAM_Flight_control_DW.baro_bias
                    section.data(93).logicalSrcIdx = 120;
                    section.data(93).dtTransOffset = 710;

                    ;% UAM_Flight_control_DW.baro_bias_var
                    section.data(94).logicalSrcIdx = 121;
                    section.data(94).dtTransOffset = 711;

                    ;% UAM_Flight_control_DW.imu_acc_buf
                    section.data(95).logicalSrcIdx = 122;
                    section.data(95).dtTransOffset = 712;

                    ;% UAM_Flight_control_DW.imu_gyro_buf
                    section.data(96).logicalSrcIdx = 123;
                    section.data(96).dtTransOffset = 862;

                    ;% UAM_Flight_control_DW.imu_dt_buf
                    section.data(97).logicalSrcIdx = 124;
                    section.data(97).dtTransOffset = 1012;

                    ;% UAM_Flight_control_DW.gps_pos_buf
                    section.data(98).logicalSrcIdx = 125;
                    section.data(98).dtTransOffset = 1062;

                    ;% UAM_Flight_control_DW.gps_vel_buf
                    section.data(99).logicalSrcIdx = 126;
                    section.data(99).dtTransOffset = 1212;

                    ;% UAM_Flight_control_DW.gps_valid_buf
                    section.data(100).logicalSrcIdx = 127;
                    section.data(100).dtTransOffset = 1362;

                    ;% UAM_Flight_control_DW.baro_alt_buf
                    section.data(101).logicalSrcIdx = 128;
                    section.data(101).dtTransOffset = 1412;

                    ;% UAM_Flight_control_DW.baro_valid_buf
                    section.data(102).logicalSrcIdx = 129;
                    section.data(102).dtTransOffset = 1462;

                    ;% UAM_Flight_control_DW.mag_data_buf
                    section.data(103).logicalSrcIdx = 130;
                    section.data(103).dtTransOffset = 1512;

                    ;% UAM_Flight_control_DW.mag_valid_buf_p
                    section.data(104).logicalSrcIdx = 131;
                    section.data(104).dtTransOffset = 1662;

                    ;% UAM_Flight_control_DW.buf_fill
                    section.data(105).logicalSrcIdx = 132;
                    section.data(105).dtTransOffset = 1712;

                    ;% UAM_Flight_control_DW.delay_n
                    section.data(106).logicalSrcIdx = 133;
                    section.data(106).dtTransOffset = 1713;

                    ;% UAM_Flight_control_DW.accel_mag_filt
                    section.data(107).logicalSrcIdx = 134;
                    section.data(107).dtTransOffset = 1714;

                    ;% UAM_Flight_control_DW.ang_rate_mag_filt
                    section.data(108).logicalSrcIdx = 135;
                    section.data(108).dtTransOffset = 1715;

                    ;% UAM_Flight_control_DW.bad_acc_tmr
                    section.data(109).logicalSrcIdx = 136;
                    section.data(109).dtTransOffset = 1716;

                    ;% UAM_Flight_control_DW.rest_tmr
                    section.data(110).logicalSrcIdx = 137;
                    section.data(110).dtTransOffset = 1717;

                    ;% UAM_Flight_control_DW.signed_inn_lpf
                    section.data(111).logicalSrcIdx = 138;
                    section.data(111).dtTransOffset = 1718;

                    ;% UAM_Flight_control_DW.t_pos_inn
                    section.data(112).logicalSrcIdx = 139;
                    section.data(112).dtTransOffset = 1719;

                    ;% UAM_Flight_control_DW.t_neg_inn
                    section.data(113).logicalSrcIdx = 140;
                    section.data(113).dtTransOffset = 1720;

                    ;% UAM_Flight_control_DW.t_last_hor_aid
                    section.data(114).logicalSrcIdx = 141;
                    section.data(114).dtTransOffset = 1721;

                    ;% UAM_Flight_control_DW.t_last_ver_aid
                    section.data(115).logicalSrcIdx = 142;
                    section.data(115).dtTransOffset = 1722;

                    ;% UAM_Flight_control_DW.gps_pos_innov_filt
                    section.data(116).logicalSrcIdx = 143;
                    section.data(116).dtTransOffset = 1723;

                    ;% UAM_Flight_control_DW.gps_vel_innov_filt
                    section.data(117).logicalSrcIdx = 144;
                    section.data(117).dtTransOffset = 1725;

                    ;% UAM_Flight_control_DW.gps_pos_fail_tmr
                    section.data(118).logicalSrcIdx = 145;
                    section.data(118).dtTransOffset = 1728;

                    ;% UAM_Flight_control_DW.gps_vel_fail_tmr
                    section.data(119).logicalSrcIdx = 146;
                    section.data(119).dtTransOffset = 1729;

                    ;% UAM_Flight_control_DW.mag_innov_filt
                    section.data(120).logicalSrcIdx = 147;
                    section.data(120).dtTransOffset = 1730;

                    ;% UAM_Flight_control_DW.mag_fail_tmr
                    section.data(121).logicalSrcIdx = 148;
                    section.data(121).dtTransOffset = 1733;

                    ;% UAM_Flight_control_DW.gsf_yaw_a
                    section.data(122).logicalSrcIdx = 149;
                    section.data(122).dtTransOffset = 1734;

                    ;% UAM_Flight_control_DW.gsf_vne
                    section.data(123).logicalSrcIdx = 150;
                    section.data(123).dtTransOffset = 1739;

                    ;% UAM_Flight_control_DW.gsf_Pf
                    section.data(124).logicalSrcIdx = 151;
                    section.data(124).dtTransOffset = 1749;

                    ;% UAM_Flight_control_DW.gsf_wt
                    section.data(125).logicalSrcIdx = 152;
                    section.data(125).dtTransOffset = 1794;

                    ;% UAM_Flight_control_DW.yaw_reset_cnt
                    section.data(126).logicalSrcIdx = 153;
                    section.data(126).dtTransOffset = 1799;

                    ;% UAM_Flight_control_DW.pos_reset_cnt
                    section.data(127).logicalSrcIdx = 154;
                    section.data(127).dtTransOffset = 1800;

                    ;% UAM_Flight_control_DW.o_q
                    section.data(128).logicalSrcIdx = 155;
                    section.data(128).dtTransOffset = 1801;

                    ;% UAM_Flight_control_DW.o_v
                    section.data(129).logicalSrcIdx = 156;
                    section.data(129).dtTransOffset = 1805;

                    ;% UAM_Flight_control_DW.o_p
                    section.data(130).logicalSrcIdx = 157;
                    section.data(130).dtTransOffset = 1808;

                    ;% UAM_Flight_control_DW.homeLLA
                    section.data(131).logicalSrcIdx = 158;
                    section.data(131).dtTransOffset = 1811;

                    ;% UAM_Flight_control_DW.prevArming
                    section.data(132).logicalSrcIdx = 159;
                    section.data(132).dtTransOffset = 1814;

                    ;% UAM_Flight_control_DW.sf_internal_action_state_placeh
                    section.data(133).logicalSrcIdx = 162;
                    section.data(133).dtTransOffset = 1815;

                    ;% UAM_Flight_control_DW.sf_internal_action_state_plac_m
                    section.data(134).logicalSrcIdx = 163;
                    section.data(134).dtTransOffset = 1816;

                    ;% UAM_Flight_control_DW.sf_internal_action_state_plac_f
                    section.data(135).logicalSrcIdx = 164;
                    section.data(135).dtTransOffset = 1817;

                    ;% UAM_Flight_control_DW.sf_internal_action_state_plac_a
                    section.data(136).logicalSrcIdx = 165;
                    section.data(136).dtTransOffset = 1818;

                    ;% UAM_Flight_control_DW.sf_internal_action_state_plac_n
                    section.data(137).logicalSrcIdx = 166;
                    section.data(137).dtTransOffset = 1819;

                    ;% UAM_Flight_control_DW.sf_internal_action_state_plac_g
                    section.data(138).logicalSrcIdx = 167;
                    section.data(138).dtTransOffset = 1820;

                    ;% UAM_Flight_control_DW.sf_internal_action_state_plac_k
                    section.data(139).logicalSrcIdx = 168;
                    section.data(139).dtTransOffset = 1821;

                    ;% UAM_Flight_control_DW.sf_internal_action_state_plac_j
                    section.data(140).logicalSrcIdx = 169;
                    section.data(140).dtTransOffset = 1822;

                    ;% UAM_Flight_control_DW.sf_internal_action_state_plac_i
                    section.data(141).logicalSrcIdx = 170;
                    section.data(141).dtTransOffset = 1823;

                    ;% UAM_Flight_control_DW.outWPS
                    section.data(142).logicalSrcIdx = 171;
                    section.data(142).dtTransOffset = 1824;

                    ;% UAM_Flight_control_DW.outWPS_e
                    section.data(143).logicalSrcIdx = 172;
                    section.data(143).dtTransOffset = 1832;

                    ;% UAM_Flight_control_DW.outWPS_p
                    section.data(144).logicalSrcIdx = 173;
                    section.data(144).dtTransOffset = 1840;

                    ;% UAM_Flight_control_DW.PrevY
                    section.data(145).logicalSrcIdx = 174;
                    section.data(145).dtTransOffset = 1848;

                    ;% UAM_Flight_control_DW.PrevY_k
                    section.data(146).logicalSrcIdx = 175;
                    section.data(146).dtTransOffset = 1849;

                    ;% UAM_Flight_control_DW.PrevY_i
                    section.data(147).logicalSrcIdx = 176;
                    section.data(147).dtTransOffset = 1850;

                    ;% UAM_Flight_control_DW.last_yaw_sp
                    section.data(148).logicalSrcIdx = 177;
                    section.data(148).dtTransOffset = 1851;

                    ;% UAM_Flight_control_DW.hover_thrust
                    section.data(149).logicalSrcIdx = 178;
                    section.data(149).dtTransOffset = 1852;

            nTotData = nTotData + section.nData;
            dworkMap.sections(13) = section;
            clear section

            section.nData     = 13;
            section.data(13)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.ToWorkspace_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 179;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_DW.WAYPOINT_execBlock
                    section.data(2).logicalSrcIdx = 180;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_DW.ORBIT_execBlock
                    section.data(3).logicalSrcIdx = 181;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_DW.Takeoff_execBlock
                    section.data(4).logicalSrcIdx = 182;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_DW.WP_execBlock
                    section.data(5).logicalSrcIdx = 183;
                    section.data(5).dtTransOffset = 4;

                    ;% UAM_Flight_control_DW.Orbit_execBlock
                    section.data(6).logicalSrcIdx = 184;
                    section.data(6).dtTransOffset = 5;

                    ;% UAM_Flight_control_DW.BackTransition_execBlock
                    section.data(7).logicalSrcIdx = 185;
                    section.data(7).dtTransOffset = 6;

                    ;% UAM_Flight_control_DW.ForwardTransition_execBlock
                    section.data(8).logicalSrcIdx = 186;
                    section.data(8).dtTransOffset = 7;

                    ;% UAM_Flight_control_DW.Descend_execBlock
                    section.data(9).logicalSrcIdx = 187;
                    section.data(9).dtTransOffset = 8;

                    ;% UAM_Flight_control_DW.ToLand_execBlock
                    section.data(10).logicalSrcIdx = 188;
                    section.data(10).dtTransOffset = 9;

                    ;% UAM_Flight_control_DW.Scope_PWORK.LoggedData
                    section.data(11).logicalSrcIdx = 189;
                    section.data(11).dtTransOffset = 10;

                    ;% UAM_Flight_control_DW.Scope_PWORK_g.LoggedData
                    section.data(12).logicalSrcIdx = 190;
                    section.data(12).dtTransOffset = 11;

                    ;% UAM_Flight_control_DW.Scope_PWORK_a.LoggedData
                    section.data(13).logicalSrcIdx = 191;
                    section.data(13).dtTransOffset = 12;

            nTotData = nTotData + section.nData;
            dworkMap.sections(14) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.UnitDelay_8_DSTATE
                    section.data(1).logicalSrcIdx = 192;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_DW.UnitDelay_8_DSTATE_o
                    section.data(2).logicalSrcIdx = 193;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_DW.UnitDelay_8_DSTATE_p
                    section.data(3).logicalSrcIdx = 194;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(15) = section;
            clear section

            section.nData     = 12;
            section.data(12)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.is_c1_UAM_Flight_control
                    section.data(1).logicalSrcIdx = 223;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_DW.is_c11_UAM_Flight_control
                    section.data(2).logicalSrcIdx = 224;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_DW.is_STATE_MACHINE
                    section.data(3).logicalSrcIdx = 225;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_DW.is_c3_UAM_Flight_control
                    section.data(4).logicalSrcIdx = 226;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_DW.is_GuidanceLogic
                    section.data(5).logicalSrcIdx = 227;
                    section.data(5).dtTransOffset = 4;

                    ;% UAM_Flight_control_DW.is_FIXED_WING_ENTRY
                    section.data(6).logicalSrcIdx = 228;
                    section.data(6).dtTransOffset = 5;

                    ;% UAM_Flight_control_DW.is_FIXED_WING_ORBIT
                    section.data(7).logicalSrcIdx = 229;
                    section.data(7).dtTransOffset = 6;

                    ;% UAM_Flight_control_DW.is_FIXED_WING_WAYPOINT
                    section.data(8).logicalSrcIdx = 230;
                    section.data(8).dtTransOffset = 7;

                    ;% UAM_Flight_control_DW.is_Land
                    section.data(9).logicalSrcIdx = 231;
                    section.data(9).dtTransOffset = 8;

                    ;% UAM_Flight_control_DW.durationCounter_1
                    section.data(10).logicalSrcIdx = 232;
                    section.data(10).dtTransOffset = 9;

                    ;% UAM_Flight_control_DW.is_c12_UAM_Flight_control
                    section.data(11).logicalSrcIdx = 233;
                    section.data(11).dtTransOffset = 10;

                    ;% UAM_Flight_control_DW.is_STATE_MACHINE_g
                    section.data(12).logicalSrcIdx = 234;
                    section.data(12).dtTransOffset = 11;

            nTotData = nTotData + section.nData;
            dworkMap.sections(16) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.temporalCounter_i1
                    section.data(1).logicalSrcIdx = 237;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(17) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.UnitDelay_1_DSTATE_e
                    section.data(1).logicalSrcIdx = 238;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_DW.UnitDelay_9_DSTATE
                    section.data(2).logicalSrcIdx = 239;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_DW.UnitDelay_9_DSTATE_c
                    section.data(3).logicalSrcIdx = 240;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_DW.UnitDelay_9_DSTATE_h
                    section.data(4).logicalSrcIdx = 241;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_DW.UnitDelay_DSTATE_d
                    section.data(5).logicalSrcIdx = 242;
                    section.data(5).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            dworkMap.sections(18) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.DelayInput1_DSTATE
                    section.data(1).logicalSrcIdx = 243;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_DW.DelayInput1_DSTATE_e
                    section.data(2).logicalSrcIdx = 244;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_DW.DelayInput1_DSTATE_b
                    section.data(3).logicalSrcIdx = 245;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_DW.DelayInput1_DSTATE_f
                    section.data(4).logicalSrcIdx = 246;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            dworkMap.sections(19) = section;
            clear section

            section.nData     = 71;
            section.data(71)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.DiscreteTimeIntegrator_DSTATE
                    section.data(1).logicalSrcIdx = 247;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_DW.DiscreteTimeIntegrator_DSTATE_i
                    section.data(2).logicalSrcIdx = 248;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_DW.SwitchCase_ActiveSubsystem_m
                    section.data(3).logicalSrcIdx = 250;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_DW.Auto_SubsysRanBC
                    section.data(4).logicalSrcIdx = 251;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_DW.Emergency_SubsysRanBC
                    section.data(5).logicalSrcIdx = 252;
                    section.data(5).dtTransOffset = 4;

                    ;% UAM_Flight_control_DW.Auto_SubsysRanBC_l
                    section.data(6).logicalSrcIdx = 253;
                    section.data(6).dtTransOffset = 5;

                    ;% UAM_Flight_control_DW.TmpIfAtGuidanceLogicFIXED_WING_
                    section.data(7).logicalSrcIdx = 254;
                    section.data(7).dtTransOffset = 6;

                    ;% UAM_Flight_control_DW.TmpIfAtGuidanceLogicWPInport4_A
                    section.data(8).logicalSrcIdx = 255;
                    section.data(8).dtTransOffset = 7;

                    ;% UAM_Flight_control_DW.TmpIfAtGuidanceLogicLandToLandI
                    section.data(9).logicalSrcIdx = 256;
                    section.data(9).dtTransOffset = 8;

                    ;% UAM_Flight_control_DW.GuidanceLogicWP_SubsysRanBC
                    section.data(10).logicalSrcIdx = 257;
                    section.data(10).dtTransOffset = 9;

                    ;% UAM_Flight_control_DW.TriggeredSubsystem_SubsysRanBC
                    section.data(11).logicalSrcIdx = 258;
                    section.data(11).dtTransOffset = 10;

                    ;% UAM_Flight_control_DW.GuidanceLogicTakeoff_SubsysRanB
                    section.data(12).logicalSrcIdx = 259;
                    section.data(12).dtTransOffset = 11;

                    ;% UAM_Flight_control_DW.GuidanceLogicOrbit_SubsysRanBC
                    section.data(13).logicalSrcIdx = 260;
                    section.data(13).dtTransOffset = 12;

                    ;% UAM_Flight_control_DW.GuidanceLogicLandToLand_SubsysR
                    section.data(14).logicalSrcIdx = 261;
                    section.data(14).dtTransOffset = 13;

                    ;% UAM_Flight_control_DW.GuidanceLogicLandDescend_Subsys
                    section.data(15).logicalSrcIdx = 262;
                    section.data(15).dtTransOffset = 14;

                    ;% UAM_Flight_control_DW.GuidanceLogicForwardTransition_
                    section.data(16).logicalSrcIdx = 263;
                    section.data(16).dtTransOffset = 15;

                    ;% UAM_Flight_control_DW.GuidanceLogicFIXED_WING_WAYPOIN
                    section.data(17).logicalSrcIdx = 264;
                    section.data(17).dtTransOffset = 16;

                    ;% UAM_Flight_control_DW.GuidanceLogicFIXED_WING_ORBITOR
                    section.data(18).logicalSrcIdx = 265;
                    section.data(18).dtTransOffset = 17;

                    ;% UAM_Flight_control_DW.GuidanceLogicBackTransition_Sub
                    section.data(19).logicalSrcIdx = 266;
                    section.data(19).dtTransOffset = 18;

                    ;% UAM_Flight_control_DW.Manual_SubsysRanBC
                    section.data(20).logicalSrcIdx = 267;
                    section.data(20).dtTransOffset = 19;

                    ;% UAM_Flight_control_DW.Emergency_SubsysRanBC_o
                    section.data(21).logicalSrcIdx = 268;
                    section.data(21).dtTransOffset = 20;

                    ;% UAM_Flight_control_DW.multicopterController_SubsysRan
                    section.data(22).logicalSrcIdx = 269;
                    section.data(22).dtTransOffset = 21;

                    ;% UAM_Flight_control_DW.Scheduler_SubsysRanBC
                    section.data(23).logicalSrcIdx = 270;
                    section.data(23).dtTransOffset = 22;

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem3_Subs
                    section.data(24).logicalSrcIdx = 271;
                    section.data(24).dtTransOffset = 23;

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem1_Subs
                    section.data(25).logicalSrcIdx = 272;
                    section.data(25).dtTransOffset = 24;

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem_Subsy
                    section.data(26).logicalSrcIdx = 273;
                    section.data(26).dtTransOffset = 25;

                    ;% UAM_Flight_control_DW.FixedWingController_SubsysRanBC
                    section.data(27).logicalSrcIdx = 274;
                    section.data(27).dtTransOffset = 26;

                    ;% UAM_Flight_control_DW.AttitudeController_SubsysRanBC
                    section.data(28).logicalSrcIdx = 275;
                    section.data(28).dtTransOffset = 27;

                    ;% UAM_Flight_control_DW.PitchRollController_SubsysRanBC
                    section.data(29).logicalSrcIdx = 276;
                    section.data(29).dtTransOffset = 28;

                    ;% UAM_Flight_control_DW.Auto_SubsysRanBC_g
                    section.data(30).logicalSrcIdx = 277;
                    section.data(30).dtTransOffset = 29;

                    ;% UAM_Flight_control_DW.Scheduler_SubsysRanBC_b
                    section.data(31).logicalSrcIdx = 278;
                    section.data(31).dtTransOffset = 30;

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem3_Su_j
                    section.data(32).logicalSrcIdx = 279;
                    section.data(32).dtTransOffset = 31;

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem1_Su_i
                    section.data(33).logicalSrcIdx = 280;
                    section.data(33).dtTransOffset = 32;

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem_Sub_j
                    section.data(34).logicalSrcIdx = 281;
                    section.data(34).dtTransOffset = 33;

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem2_Subs
                    section.data(35).logicalSrcIdx = 282;
                    section.data(35).dtTransOffset = 34;

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem1_Su_l
                    section.data(36).logicalSrcIdx = 283;
                    section.data(36).dtTransOffset = 35;

                    ;% UAM_Flight_control_DW.MulticopterController_SubsysRan
                    section.data(37).logicalSrcIdx = 284;
                    section.data(37).dtTransOffset = 36;

                    ;% UAM_Flight_control_DW.transitioncontroller_SubsysRanB
                    section.data(38).logicalSrcIdx = 285;
                    section.data(38).dtTransOffset = 37;

                    ;% UAM_Flight_control_DW.HorizontalPositionControl_Subsy
                    section.data(39).logicalSrcIdx = 286;
                    section.data(39).dtTransOffset = 38;

                    ;% UAM_Flight_control_DW.TriggeredSubsystem_SubsysRanB_l
                    section.data(40).logicalSrcIdx = 287;
                    section.data(40).dtTransOffset = 39;

                    ;% UAM_Flight_control_DW.FixedWingController_SubsysRan_g
                    section.data(41).logicalSrcIdx = 288;
                    section.data(41).dtTransOffset = 40;

                    ;% UAM_Flight_control_DW.RollSPfromPathManager_SubsysRan
                    section.data(42).logicalSrcIdx = 289;
                    section.data(42).dtTransOffset = 41;

                    ;% UAM_Flight_control_DW.PitchAirspeedSPfromController_S
                    section.data(43).logicalSrcIdx = 290;
                    section.data(43).dtTransOffset = 42;

                    ;% UAM_Flight_control_DW.LateralGuidanceLogic_SubsysRanB
                    section.data(44).logicalSrcIdx = 291;
                    section.data(44).dtTransOffset = 43;

                    ;% UAM_Flight_control_DW.AttitudeController_SubsysRanB_l
                    section.data(45).logicalSrcIdx = 292;
                    section.data(45).dtTransOffset = 44;

                    ;% UAM_Flight_control_DW.RudderHeadingController_SubsysR
                    section.data(46).logicalSrcIdx = 293;
                    section.data(46).dtTransOffset = 45;

                    ;% UAM_Flight_control_DW.PitchRollController_SubsysRan_k
                    section.data(47).logicalSrcIdx = 294;
                    section.data(47).dtTransOffset = 46;

                    ;% UAM_Flight_control_DW.AirspeedAltitudeController_Subs
                    section.data(48).logicalSrcIdx = 295;
                    section.data(48).dtTransOffset = 47;

                    ;% UAM_Flight_control_DW.ClimbRateSPfromGuidance_SubsysR
                    section.data(49).logicalSrcIdx = 296;
                    section.data(49).dtTransOffset = 48;

                    ;% UAM_Flight_control_DW.Altitudecontroller_SubsysRanBC
                    section.data(50).logicalSrcIdx = 297;
                    section.data(50).dtTransOffset = 49;

                    ;% UAM_Flight_control_DW.AERfromPathManager_SubsysRanBC
                    section.data(51).logicalSrcIdx = 298;
                    section.data(51).dtTransOffset = 50;

                    ;% UAM_Flight_control_DW.Manual_SubsysRanBC_o
                    section.data(52).logicalSrcIdx = 299;
                    section.data(52).dtTransOffset = 51;

                    ;% UAM_Flight_control_DW.multicopterController_SubsysR_l
                    section.data(53).logicalSrcIdx = 300;
                    section.data(53).dtTransOffset = 52;

                    ;% UAM_Flight_control_DW.Subsystem_SubsysRanBC
                    section.data(54).logicalSrcIdx = 301;
                    section.data(54).dtTransOffset = 53;

                    ;% UAM_Flight_control_DW.HorizontalPositionControl1_Subs
                    section.data(55).logicalSrcIdx = 302;
                    section.data(55).dtTransOffset = 54;

                    ;% UAM_Flight_control_DW.Integrator_PrevResetState
                    section.data(56).logicalSrcIdx = 303;
                    section.data(56).dtTransOffset = 55;

                    ;% UAM_Flight_control_DW.Filter_PrevResetState
                    section.data(57).logicalSrcIdx = 304;
                    section.data(57).dtTransOffset = 56;

                    ;% UAM_Flight_control_DW.Integrator_PrevResetState_p
                    section.data(58).logicalSrcIdx = 305;
                    section.data(58).dtTransOffset = 57;

                    ;% UAM_Flight_control_DW.Filter_PrevResetState_c
                    section.data(59).logicalSrcIdx = 306;
                    section.data(59).dtTransOffset = 58;

                    ;% UAM_Flight_control_DW.EnabledSubsystem_SubsysRanBC
                    section.data(60).logicalSrcIdx = 307;
                    section.data(60).dtTransOffset = 59;

                    ;% UAM_Flight_control_DW.AltitudeControl1_SubsysRanBC
                    section.data(61).logicalSrcIdx = 308;
                    section.data(61).dtTransOffset = 60;

                    ;% UAM_Flight_control_DW.Integrator_PrevResetState_f
                    section.data(62).logicalSrcIdx = 309;
                    section.data(62).dtTransOffset = 61;

                    ;% UAM_Flight_control_DW.Filter_PrevResetState_m
                    section.data(63).logicalSrcIdx = 310;
                    section.data(63).dtTransOffset = 62;

                    ;% UAM_Flight_control_DW.Scheduler_SubsysRanBC_f
                    section.data(64).logicalSrcIdx = 311;
                    section.data(64).dtTransOffset = 63;

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem3_Su_p
                    section.data(65).logicalSrcIdx = 312;
                    section.data(65).dtTransOffset = 64;

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem2_Su_e
                    section.data(66).logicalSrcIdx = 313;
                    section.data(66).dtTransOffset = 65;

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem1_Su_a
                    section.data(67).logicalSrcIdx = 314;
                    section.data(67).dtTransOffset = 66;

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem_Sub_k
                    section.data(68).logicalSrcIdx = 315;
                    section.data(68).dtTransOffset = 67;

                    ;% UAM_Flight_control_DW.FixedWingController_SubsysRan_j
                    section.data(69).logicalSrcIdx = 316;
                    section.data(69).dtTransOffset = 68;

                    ;% UAM_Flight_control_DW.AttitudeController_SubsysRanB_e
                    section.data(70).logicalSrcIdx = 317;
                    section.data(70).dtTransOffset = 69;

                    ;% UAM_Flight_control_DW.PitchRollController_SubsysRan_c
                    section.data(71).logicalSrcIdx = 318;
                    section.data(71).dtTransOffset = 70;

            nTotData = nTotData + section.nData;
            dworkMap.sections(20) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.last_arm
                    section.data(1).logicalSrcIdx = 319;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_DW.is_active_c1_UAM_Flight_control
                    section.data(2).logicalSrcIdx = 320;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_DW.is_active_c11_UAM_Flight_contro
                    section.data(3).logicalSrcIdx = 321;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_DW.is_active_c3_UAM_Flight_control
                    section.data(4).logicalSrcIdx = 322;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_DW.mode_start
                    section.data(5).logicalSrcIdx = 324;
                    section.data(5).dtTransOffset = 4;

                    ;% UAM_Flight_control_DW.is_active_c12_UAM_Flight_contro
                    section.data(6).logicalSrcIdx = 325;
                    section.data(6).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            dworkMap.sections(21) = section;
            clear section

            section.nData     = 18;
            section.data(18)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.init
                    section.data(1).logicalSrcIdx = 332;
                    section.data(1).dtTransOffset = 0;

                    ;% UAM_Flight_control_DW.ref_set
                    section.data(2).logicalSrcIdx = 335;
                    section.data(2).dtTransOffset = 1;

                    ;% UAM_Flight_control_DW.p0_set
                    section.data(3).logicalSrcIdx = 343;
                    section.data(3).dtTransOffset = 2;

                    ;% UAM_Flight_control_DW.initialized
                    section.data(4).logicalSrcIdx = 348;
                    section.data(4).dtTransOffset = 3;

                    ;% UAM_Flight_control_DW.state_init
                    section.data(5).logicalSrcIdx = 354;
                    section.data(5).dtTransOffset = 4;

                    ;% UAM_Flight_control_DW.bad_acc_vert
                    section.data(6).logicalSrcIdx = 382;
                    section.data(6).dtTransOffset = 5;

                    ;% UAM_Flight_control_DW.veh_at_rest
                    section.data(7).logicalSrcIdx = 385;
                    section.data(7).dtTransOffset = 6;

                    ;% UAM_Flight_control_DW.yaw_aligned
                    section.data(8).logicalSrcIdx = 405;
                    section.data(8).dtTransOffset = 7;

                    ;% UAM_Flight_control_DW.o_ok
                    section.data(9).logicalSrcIdx = 414;
                    section.data(9).dtTransOffset = 8;

                    ;% UAM_Flight_control_DW.isSet
                    section.data(10).logicalSrcIdx = 418;
                    section.data(10).dtTransOffset = 9;

                    ;% UAM_Flight_control_DW.IC_FirstOutputTime
                    section.data(11).logicalSrcIdx = 424;
                    section.data(11).dtTransOffset = 10;

                    ;% UAM_Flight_control_DW.IC_FirstOutputTime_d
                    section.data(12).logicalSrcIdx = 440;
                    section.data(12).dtTransOffset = 11;

                    ;% UAM_Flight_control_DW.Scheduler_MODE
                    section.data(13).logicalSrcIdx = 449;
                    section.data(13).dtTransOffset = 12;

                    ;% UAM_Flight_control_DW.Scheduler_MODE_a
                    section.data(14).logicalSrcIdx = 450;
                    section.data(14).dtTransOffset = 13;

                    ;% UAM_Flight_control_DW.multicopterController_MODE
                    section.data(15).logicalSrcIdx = 451;
                    section.data(15).dtTransOffset = 14;

                    ;% UAM_Flight_control_DW.HorizontalPositionControl1_MODE
                    section.data(16).logicalSrcIdx = 452;
                    section.data(16).dtTransOffset = 15;

                    ;% UAM_Flight_control_DW.AltitudeControl1_MODE
                    section.data(17).logicalSrcIdx = 453;
                    section.data(17).dtTransOffset = 16;

                    ;% UAM_Flight_control_DW.Scheduler_MODE_p
                    section.data(18).logicalSrcIdx = 454;
                    section.data(18).dtTransOffset = 17;

            nTotData = nTotData + section.nData;
            dworkMap.sections(22) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.Emergency_b.SwitchCaseActionSubsystem_Subsy
                    section.data(1).logicalSrcIdx = 455;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(23) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem.SwitchCaseActionSubsystem_Subsy
                    section.data(1).logicalSrcIdx = 456;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(24) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem2_n.SwitchCaseActionSubsystem2_Subs
                    section.data(1).logicalSrcIdx = 457;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(25) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem3_g.SwitchCaseActionSubsystem_Subsy
                    section.data(1).logicalSrcIdx = 458;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(26) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem2_c.SwitchCaseActionSubsystem2_Subs
                    section.data(1).logicalSrcIdx = 459;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(27) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem1_m.SwitchCaseActionSubsystem1_Subs
                    section.data(1).logicalSrcIdx = 460;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(28) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem_e.SwitchCaseActionSubsystem_Subsy
                    section.data(1).logicalSrcIdx = 461;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(29) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.sf_MATLABFunction_j.sfEvent
                    section.data(1).logicalSrcIdx = 462;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(30) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.sf_MATLABFunction_j.doneDoubleBufferReInit
                    section.data(1).logicalSrcIdx = 463;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(31) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.sf_MATLABFunction_er.sfEvent
                    section.data(1).logicalSrcIdx = 464;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(32) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.sf_MATLABFunction_er.doneDoubleBufferReInit
                    section.data(1).logicalSrcIdx = 465;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(33) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem2_g.SwitchCaseActionSubsystem2_Subs
                    section.data(1).logicalSrcIdx = 466;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(34) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem3_j.SwitchCaseActionSubsystem_Subsy
                    section.data(1).logicalSrcIdx = 467;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(35) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem_o.SwitchCaseActionSubsystem_Subsy
                    section.data(1).logicalSrcIdx = 468;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(36) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.sf_MATLABFunction_g.sfEvent
                    section.data(1).logicalSrcIdx = 469;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(37) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.sf_MATLABFunction_g.doneDoubleBufferReInit
                    section.data(1).logicalSrcIdx = 470;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(38) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.sf_MATLABFunction_cg.sfEvent
                    section.data(1).logicalSrcIdx = 471;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(39) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.sf_MATLABFunction_cg.doneDoubleBufferReInit
                    section.data(1).logicalSrcIdx = 472;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(40) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.sf_MATLABFunction1_g.sfEvent
                    section.data(1).logicalSrcIdx = 473;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(41) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.sf_MATLABFunction1_g.doneDoubleBufferReInit
                    section.data(1).logicalSrcIdx = 474;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(42) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.sf_MATLABFunction_b.sfEvent
                    section.data(1).logicalSrcIdx = 475;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(43) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.sf_MATLABFunction_b.doneDoubleBufferReInit
                    section.data(1).logicalSrcIdx = 476;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(44) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem3.SwitchCaseActionSubsystem_Subsy
                    section.data(1).logicalSrcIdx = 477;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(45) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem2_f.SwitchCaseActionSubsystem2_Subs
                    section.data(1).logicalSrcIdx = 478;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(46) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem1_e.SwitchCaseActionSubsystem1_Subs
                    section.data(1).logicalSrcIdx = 479;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(47) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.SwitchCaseActionSubsystem_kk.SwitchCaseActionSubsystem_Subsy
                    section.data(1).logicalSrcIdx = 480;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(48) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.sf_MATLABFunction_a.sfEvent
                    section.data(1).logicalSrcIdx = 481;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(49) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.sf_MATLABFunction_a.doneDoubleBufferReInit
                    section.data(1).logicalSrcIdx = 482;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(50) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.sf_MATLABFunction_c.sfEvent
                    section.data(1).logicalSrcIdx = 483;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(51) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% UAM_Flight_control_DW.sf_MATLABFunction_c.doneDoubleBufferReInit
                    section.data(1).logicalSrcIdx = 484;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(52) = section;
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


    targMap.checksum0 = 2306153919;
    targMap.checksum1 = 21162570;
    targMap.checksum2 = 1677712212;
    targMap.checksum3 = 4241420299;

