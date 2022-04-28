cd hardware/qcom-caf/msm8996
rm -rf audio
rm -rf display
rm -rf media
cd ../../..

git clone https://github.com/YadavMohit19/hardware_qcom-caf -b audio-msm8996-s hardware/qcom-caf/msm8996/audio
git clone https://github.com/YadavMohit19/hardware_qcom-caf -b display-msm8996-s hardware/qcom-caf/msm8996/display
git clone https://github.com/YadavMohit19/hardware_qcom-caf -b media-msm8996-s hardware/qcom-caf/msm8996/media
