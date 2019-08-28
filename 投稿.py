#coding=utf-8
import unittest
import time
from macaca import WebDriver
import re
import cv2
import numpy as np
from findit import FindIt
import cv2
import pprint
import time
class opencvSample:

    def __init__(self, sourceimage):
        self.sourceimage = sourceimage

    def match(self, templateimage, threshold=0.8):
        image = cv2.imread(self.sourceimage)
        template = cv2.imread(templateimage)
        result = cv2.matchTemplate(image, template, cv2.TM_CCOEFF_NORMED)
        similarity = cv2.minMaxLoc(result)[1]
        if similarity < threshold:
            return similarity
        else:
            return np.unravel_index(result.argmax(), result.shape)



desired_caps = {
    'platformName': 'android',
    #'app': 'https://npmcdn.com/android-app-bootstrap@latest/android_app_bootstrap/build/outputs/apk/android_app_bootstrap-debug.apk',
    "package": "com.tencent.karaoke",
    'deviceName': 'taimen',
    'reuse': 3
}

server_url = {
    'hostname': '127.0.0.1',
    'port': 3456
}

class MacacaTest(unittest.TestCase):
    def setUp(self):
        self.driver = WebDriver(desired_caps, server_url)
        self.driver.init()

    def tearDown(self):
        self.driver.quit()
        
    def process(self,str):
        el=self.driver.element_by_xpath(str)
        el.click()
        time.sleep(2)
    def find_pos(self,target):
        fi = FindIt()
        fi.load_template('target', pic_path=target)
        self.driver.save_screenshot('pics/s.png')
        result = fi.find(
            target_pic_name='s',
            target_pic_path='pics/s.png',
        )
        x = result['data']['target']['FeatureEngine']['target_point'][0]
        y = result['data']['target']['FeatureEngine']['target_point'][1]
        return x,y
    def content(self):
        for i in range(2, 5):
            target = 'pics/' + str(i) + '.png'

            # print(target)
            x, y = MacacaTest.find_pos(self, target)
            print((x, y))
            self.driver.stouch('tap', {'x': x, 'y': y})
            i += 1
            time.sleep(1)


    def test_macaca(self):
        # n=0
        # for line in open("xpath.txt"):
        #     MacacaTest.process(self, line.replace('\n', ''))
        #     self.driver.save_screenshot("screenshot"+str(n)+".png")
        #     n+=1
        #
        # matcher = opencvSample('./vip.png')
        # for item in ['./screenshot1.png']:
        #     if matcher.match(item) == (0,0):
        #         print("图片校验成功！")
        #     else:
        #         print("图片校验失败！")
        #pprint.pprint(result['data']['target']['FeatureEngine']['target_point'])

        # {'data': {'app_store_logo': {'FeatureEngine': (94.66734313964844,
        #                                                380.8362731933594),
        #                              'TemplateEngine': (56.0, 340.0)},
        #           'wechat_logo': {'FeatureEngine': (528.9216674804687,
        #                                             383.21449890136716),
        #                           'TemplateEngine': (475.0, 344.0)}},
        #  'target_name': 'screen',
        #  'target_path': 'wechat_screen.png'}
        # fi = FindIt()
        # fi.load_template('target', pic_path='pics/target.png')
        #
        #
        # result = fi.find(
        #     target_pic_name='s',
        #     target_pic_path='pics/s.png',
        # )
        # x=result['data']['target']['FeatureEngine']['target_point'][0]
        # y=result['data']['target']['FeatureEngine']['target_point'][1]
        #print(result['data']['target']['FeatureEngine']['target_point'][0])

        #财富用例



        for i in range(1,4):
            target = 'pics/1-'+str(i)+'.png'

            # print(target)
            x, y = MacacaTest.find_pos(self, target)
            print((x, y))
            self.driver.stouch('tap', {'x': x, 'y': y})
            time.sleep(1)
            MacacaTest.content(self)



        # for i in range(2,5):
        #     target ='pics/'+str(i)+'.png'
        #
        #     #print(target)
        #     x, y = MacacaTest.find_pos(self,target)
        #     print((x,y))
        #     self.driver.stouch('tap', {'x': x, 'y': y})
        #     i+=1






if __name__ == '__main__':
    MacacaTest.test_macaca()