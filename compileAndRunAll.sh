FOLDERS="*/"
for d in $FOLDERS ; do
    cd "$d"
    echo "$d"
    sh compileAndRun.sh
    cd ".."   
done
