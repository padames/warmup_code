#!/usr/bin/env bash

#Prepare the credentials for git to ssh into the remote

if (( $# != 1 )); then
    >&2 echo "I need the GitHub URL of the repo to clone via ssh, try again"
else
    >&2 echo "Will add remote: $1"
fi
    
eval "$(ssh-agent -s)"
ssh-add ~/.ssh/id_ed25519_padames



git remote add origin $1
git branch -M main
git push -u origin main
