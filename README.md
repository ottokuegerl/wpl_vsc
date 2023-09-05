# wpl_vsc


## Ensure that your own SSH key is set up and working
   ssh -T git@github.com

   The authenticity of host 'github.com (140.82.121.3)' can't be established.
   ED25519 key fingerprint is SHA256:+DiY3wvvV6TuJJhbpZisF/zLDA0zPMSvHdkr4UvCOqU.
   This key is not known by any other names.
   Are you sure you want to continue connecting (yes/no/[fingerprint])? yes
   Warning: Permanently added 'github.com' (ED25519) to the list of known hosts.
   Hi ottokuegerl! You've successfully authenticated, but GitHub does not provide shell access.

## cd /home/nuc8/05_development/05_vcs_projects

## start SSH-agent in background
    eval "$(ssh-agent -s)"

### add existing key to SSH-agent
    ssh-add ~/.ssh/git_id_rsa
      
### check that your key is visible to ssh-agent
    ssh-add -L

## initialize git repository
    git init

## add remote repository
    git remote add origin https://github.com/ottokuegerl/wpl_vsc

## set remote URL to SSH
    git remote set-url origin git@github.com:ottokuegerl/wpl_vsc
   now we are able to pull/push from/to github using our keys for authentication

## create on github directory "wpl_vsc"
   https://github.com/ottokuegerl/wpl_vsc
   
## pull latest changes
    git pull origin main

## Set merge as the default for this repository
    git config pull.rebase false
    git pull origin main  # Perform the merge
    git pull origin main --allow-unrelated-histories

## status
    git status

## add all files
    git add .
   
## commit yout changes
    git commit -m "first commit"

## push changes to remote github repository
    git push origin main

