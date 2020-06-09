#! /usr/bin/env bash

# Stop on errors
set -o errexit

# Execute script only in a CI environment
if [ "$CI" != "true" ]
then
    echo -e "\e[35m\e[1m Error!\e[0m Trying to execute a CI script in a non-CI environment. Exiting script."
    exit 1
fi

sudo apt-get install build-essential python3-pip
sudo -H pip3 install -U pip
hash -r
pip3 install --user cmake
