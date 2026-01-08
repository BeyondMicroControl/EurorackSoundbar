# UTF character glyph helpers


## Generate Training data on UTF8 characters (menlo_parallel_dataset.h5)
<pre>
python3 generate_data.py                        
</pre>

## Create BMP image for any given UTF8 character
<pre>
 python3 char_to_bmp.py "Ȝ"
</pre>

## Score any BMP image against UTF8 training dataset
<pre>
python3 score_glyph.py  char_64x64_0x021C.bmp --stageA-topk 5000 --stageB-radius 0 --workers 8
</pre>

