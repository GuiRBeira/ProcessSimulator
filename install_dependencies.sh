#!/bin/bash
sudo apt update
sudo apt upgrade
sudo apt install $(cat dependencies.txt)