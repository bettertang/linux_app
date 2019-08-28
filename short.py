import pprint
from findit import FindIt



# fi = FindIt()
# fi.load_template('target', pic_path='pics/target.png')
#
# result = fi.find(
#     target_pic_name='s',
#     target_pic_path='pics/1.png',
# )
#
# pprint.pprint(result)

for i in range(1, 5):
    target = 'pics/' + str(i) + '.png'
    print(target)
