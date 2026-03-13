%% TransitionMission 정의
guidanceType = 3;

TransitionMission(1).mode = 2;  
TransitionMission(1).position = [-0.3; 0; -0.7];  
TransitionMission(1).params = [0; 0; 0; 0];  

TransitionMission(2).mode = 2;  
TransitionMission(2).position = [-0.3; 0; -0.7];   
TransitionMission(2).params = [0; 0; 0; 0];

TransitionMission(3).mode = 4;  
TransitionMission(3).position = [-0.3; 0; 0];   
TransitionMission(3).params = [0; 0; 0; 0];
% 
% TransitionMission(4).mode = 2;  
% TransitionMission(4).position = [0; 4000; -200];   
% TransitionMission(4).params = [0; 0; 0; 0];
% 
% TransitionMission(5).mode = 2;  
% TransitionMission(5).position = [0; 6000; -100];   
% TransitionMission(5).params = [0; 0; 0; 0];
% 
% TransitionMission(6).mode = 6;  
% TransitionMission(6).position = [0; 6000; -100];  
% TransitionMission(6).params = [0; 0; 0; 0];
% 
% 
% TransitionMission(7).mode = 2;
% TransitionMission(7).position = [0; 9000; -100];
% TransitionMission(7).params = [0; 0; 0; 0];
% 
% TransitionMission(8).mode = 2;
% TransitionMission(8).position = [0; 9000; -70];
% TransitionMission(8).params = [0; 0; 0; 0];
% 
% TransitionMission(9) = struct('mode', 2, 'position', [0; 9000; -30], 'params', [0; 0; 0; 0]);
% TransitionMission(10) = struct('mode', 4, 'position', [0; 9000; 0], 'params', [0; 0; 0; 0]);

%% Simulink 모델 로드 (선택 사항)
load_system('UAM_Flight_control.slx');

%set_param('UAM_Flight_control/Flightmodetype/Mission', 'PortDimensions', '9');
set_param('UAM_Flight_control/GNC/Mission', 'PortDimensions', '10');

%% 데이터 사전에 TransitionMission 저장
dataDictionaryObj = Simulink.data.dictionary.open('UAM_data.sldd');
section = getSection(dataDictionaryObj, 'Design Data');
assignin(section, 'TransitionMission', TransitionMission);
saveChanges(dataDictionaryObj);
close(dataDictionaryObj);
