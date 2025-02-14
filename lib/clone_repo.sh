#!/bin/bash
# This script clones a git repository

# Define the repository URL
REPO_URL1="https://github.com/tenergyinnovation/tiny32_v3.git"
# REPO_URL2="https://github.com/lukas-kurka/winsen-sensors-lib.git"
REPO_URL3="https://github.com/plerup/espsoftwareserial.git"





# Define the target directory (optional)
TARGET_DIR="repository"

# Clone the repository
git clone $REPO_URL1
git clone $REPO_URL2
# git clone $REPO_URL3

# cp -r ./winsen-sensors-lib/lib/ZE14-O3 ./
# cd ZE14-O3
# mkdir src 
# mv ZE14.* ./src

# echo "****************************"
# echo "* Success run clone script *"
# echo "****************************"