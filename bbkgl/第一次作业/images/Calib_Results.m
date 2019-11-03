% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly executed under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 3134.330764302692400 ; 3127.320696388179800 ];

%-- Principal point:
cc = [ 2024.841857305883900 ; 1492.533869936377600 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ 0.068083052888150 ; -0.167313457450124 ; 0.001577657433806 ; 0.000128956195833 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 13.892496763017606 ; 13.689599115970539 ];

%-- Principal point uncertainty:
cc_error = [ 11.355933135605547 ; 10.531576954480892 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.006586395445456 ; 0.014859677363690 ; 0.001031831565284 ; 0.001103537561356 ; 0.000000000000000 ];

%-- Image size:
nx = 4032;
ny = 3024;


%-- Various other variables (may be ignored if you do not use the Matlab Calibration Toolbox):
%-- Those variables are used to control which intrinsic parameters should be optimized

n_ima = 12;						% Number of calibration images
est_fc = [ 1 ; 1 ];					% Estimation indicator of the two focal variables
est_aspect_ratio = 1;				% Estimation indicator of the aspect ratio fc(2)/fc(1)
center_optim = 1;					% Estimation indicator of the principal point
est_alpha = 0;						% Estimation indicator of the skew coefficient
est_dist = [ 1 ; 1 ; 1 ; 1 ; 0 ];	% Estimation indicator of the distortion coefficients


%-- Extrinsic parameters:
%-- The rotation (omc_kk) and the translation (Tc_kk) vectors for every calibration image and their uncertainties

%-- Image #1:
omc_1 = [ 2.130897e+00 ; 2.136532e+00 ; 2.597985e-02 ];
Tc_1  = [ -9.398985e+02 ; 3.011751e+00 ; 2.015494e+03 ];
omc_error_1 = [ 3.771644e-03 ; 3.971572e-03 ; 6.734880e-03 ];
Tc_error_1  = [ 7.395291e+00 ; 7.007164e+00 ; 1.024549e+01 ];

%-- Image #2:
omc_2 = [ 2.130697e+00 ; 2.077485e+00 ; 2.297406e-01 ];
Tc_2  = [ 9.625891e+01 ; -2.971025e+01 ; 1.845240e+03 ];
omc_error_2 = [ 3.326925e-03 ; 2.099208e-03 ; 7.220861e-03 ];
Tc_error_2  = [ 6.708086e+00 ; 6.207824e+00 ; 8.303553e+00 ];

%-- Image #3:
omc_3 = [ 2.266533e+00 ; 2.088725e+00 ; 5.395344e-01 ];
Tc_3  = [ -4.246873e+01 ; -4.549421e+02 ; 1.570299e+03 ];
omc_error_3 = [ 3.474848e-03 ; 2.463843e-03 ; 5.996006e-03 ];
Tc_error_3  = [ 5.814443e+00 ; 5.284781e+00 ; 7.031586e+00 ];

%-- Image #4:
omc_4 = [ -1.865050e+00 ; -2.058001e+00 ; 1.134134e-01 ];
Tc_4  = [ -1.026314e+03 ; -7.208758e+02 ; 2.219813e+03 ];
omc_error_4 = [ 3.149995e-03 ; 2.330264e-03 ; 5.549118e-03 ];
Tc_error_4  = [ 8.135709e+00 ; 7.806198e+00 ; 1.025649e+01 ];

%-- Image #5:
omc_5 = [ -2.190706e+00 ; -2.214776e+00 ; -1.589211e-01 ];
Tc_5  = [ -5.191887e+02 ; -3.034342e+02 ; 1.797825e+03 ];
omc_error_5 = [ 2.502871e-03 ; 2.688184e-03 ; 5.629399e-03 ];
Tc_error_5  = [ 6.620446e+00 ; 6.174251e+00 ; 8.511505e+00 ];

%-- Image #6:
omc_6 = [ -1.833526e+00 ; -2.003939e+00 ; 1.212191e-01 ];
Tc_6  = [ -1.263968e+03 ; 4.346081e+01 ; 2.396725e+03 ];
omc_error_6 = [ 3.244914e-03 ; 3.117273e-03 ; 4.788807e-03 ];
Tc_error_6  = [ 8.720815e+00 ; 8.588902e+00 ; 1.099727e+01 ];

%-- Image #7:
omc_7 = [ -6.903252e-01 ; -2.911488e+00 ; -4.517029e-01 ];
Tc_7  = [ 5.982248e+02 ; -1.725425e+02 ; 2.238107e+03 ];
omc_error_7 = [ 1.088869e-03 ; 4.202630e-03 ; 6.247243e-03 ];
Tc_error_7  = [ 8.203791e+00 ; 7.692787e+00 ; 1.034853e+01 ];

%-- Image #8:
omc_8 = [ -1.798307e+00 ; -1.830169e+00 ; 6.664102e-02 ];
Tc_8  = [ -1.206405e+03 ; -7.462129e+02 ; 2.622480e+03 ];
omc_error_8 = [ 3.319036e-03 ; 2.327532e-03 ; 4.898739e-03 ];
Tc_error_8  = [ 9.767982e+00 ; 9.226479e+00 ; 1.278431e+01 ];

%-- Image #9:
omc_9 = [ 1.743464e+00 ; 1.750815e+00 ; 6.690234e-01 ];
Tc_9  = [ -4.892372e+02 ; -3.231052e+02 ; 1.511748e+03 ];
omc_error_9 = [ 2.974396e-03 ; 2.507666e-03 ; 4.803633e-03 ];
Tc_error_9  = [ 5.586754e+00 ; 5.142360e+00 ; 7.299752e+00 ];

%-- Image #10:
omc_10 = [ -2.217512e+00 ; -2.151244e+00 ; -1.765363e-01 ];
Tc_10  = [ 8.695618e+02 ; -6.421946e+02 ; 3.221615e+03 ];
omc_error_10 = [ 3.448972e-03 ; 4.731988e-03 ; 8.547601e-03 ];
Tc_error_10  = [ 1.199597e+01 ; 1.100550e+01 ; 1.473151e+01 ];

%-- Image #11:
omc_11 = [ 9.958202e-01 ; 2.816403e+00 ; 2.645226e-02 ];
Tc_11  = [ 7.967790e+02 ; -3.691325e+01 ; 3.168339e+03 ];
omc_error_11 = [ 2.569754e-03 ; 4.512281e-03 ; 7.799448e-03 ];
Tc_error_11  = [ 1.149224e+01 ; 1.086151e+01 ; 1.456365e+01 ];

%-- Image #12:
omc_12 = [ -9.758292e-01 ; -2.876870e+00 ; 2.185452e-01 ];
Tc_12  = [ 3.461580e+02 ; -1.469203e+02 ; 5.180939e+03 ];
omc_error_12 = [ 5.010073e-03 ; 1.976516e-02 ; 2.609930e-02 ];
Tc_error_12  = [ 1.880652e+01 ; 1.748226e+01 ; 2.417883e+01 ];

