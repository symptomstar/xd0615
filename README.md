# xd0615
> 本节课需要自己搜索掌握的知识：
> 1. 安装git工具
> 2. 设置ssh-keygen，直接访问github。
> 3. git的基本操作。

> 作业：
申请一个github账户，在仓库里，创建一个以xd0615命名的仓库，将今天的学习笔记整理到仓库的readme内。

## Git:版本控制软件
便于多人协作
在服务器中创建路径，获取地址中内容进行编辑，防止先前修改的版本被覆盖


## 创建仓库的步骤
#### 1.进入github.com
![7a69f5aa8160262ae62e2b94046edca6.png](http://s1.wailian.download/2020/06/16/7a69f5aa8160262ae62e2b94046edca6.png)
#### 2.创建仓库界面
![1520b92c6b8664f120451bed821833b5.png](http://s1.wailian.download/2020/06/16/1520b92c6b8664f120451bed821833b5.png)
#### 3.创建链接的过程
（地址有https以及ssh两种格式，设置ssh-key需要复制ssh格式）
![3920d450320af16eeb85ebde479d5d0f.png](http://s1.wailian.download/2020/06/16/3920d450320af16eeb85ebde479d5d0f.png)


## 设置SSH-keygen的步骤
#### 1.进入github.com
![SSH.png](http://s1.wailian.download/2020/06/16/SSH.png)
#### 2.打开Git Bash，通过输入命令获取ssh key
![key.png](http://s1.wailian.download/2020/06/16/key.png)
#### 3.按这个流程继续操作，得到一串key
![SSH1.5.png](http://s1.wailian.download/2020/06/16/SSH1.5.png)
#### 4.把这串key复制了
![SSH1.png](http://s1.wailian.download/2020/06/16/SSH1.png)
#### 5.将key添加到账户里
![ssh2.png](http://s1.wailian.download/2020/06/16/ssh2.png)
#### 6.上一步步骤②后的操作，操作完会得到上一步的③
![ssh3.png](http://s1.wailian.download/2020/06/16/ssh3.png)
#### 7.成功
![ssh4.png](http://s1.wailian.download/2020/06/16/ssh4.png)


### （基于前面的操作）在本地操作的步骤
###### （此处特别鸣谢计科院林师丞小姐姐的友情帮助）
###### 1.打开Git Bash
###### 2.使用git clone    将项目克隆到本地（关联云仓库和本地仓库）
###### 3.用记事本打开README.md在本地编辑
###### 4.使用git add .    将修改后文件加载到缓存区（保存在本地仓库准备上传）
###### 5.使用git commit -m "注释"    命令设置注释（修改的内容、原因等，方便协作）
###### 6.使用git push    命令将本地项目更新提交到github（上传）

### 然后这节课的作业就完成啦！
### 完结撒花！开心╰(*°▽°*)╯！
哦，我好累好疲惫，现在终于可以去睡觉觉了，晚安~
