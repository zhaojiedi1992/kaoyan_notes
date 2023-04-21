source ./venv/bin/activate
git pull 
pip install -r requirements.txt
make clean && make html 

git add . 
git commit  -m "cm"

git push
