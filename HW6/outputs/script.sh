for filename in ./*; do
    sed -i '/^#/d' $filename
done