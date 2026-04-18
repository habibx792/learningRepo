# this is how to implement stregtegy pattern
# inheritance is not soltion to inheritance
# define 

# Stregies
class WalkAble:
    def walk(self):
        pass
class TalkAble:
    def talk(self):
        pass
class Flyable:
    def fly(self):
        pass
class ProjectionAble:
    def projection(self):
        pass
# concrete classes
class NormalWalk(WalkAble):
    def walk(self):
        print("Robo is normal walking..........")
class NonWalk(WalkAble):
    def walk(self):
        print("Robo cannot walk..........")
class NormalTalk(TalkAble):
    def talk(self):
        print("Robo is normal talking..........")
class NonTalk(TalkAble):
    def talk(self):
        print("Robo cannot talk..........")
class NormalFly(Flyable):
    def fly(self):
        print("Robo is normal flying..........")
class NonFly(Flyable):
    def fly(self):
        print("Robo cannot fly..........")
class ProjectionInTwoD(ProjectionAble):
    def projection(self):
        print("Robo is projecting in 2D..........")
class ProjectionInThreeD(ProjectionAble):
    def projection(self):
        print("Robo is projecting in 3D..........")
# clint class 
class Robot:
    def __init__(self, walk_behavior, talk_behavior, fly_behavior, projection_behavior):
        self.walk_behavior = walk_behavior
        self.talk_behavior = talk_behavior
        self.fly_behavior = fly_behavior
        self.projection_behavior = projection_behavior
    def fly(self):
        self.fly_behavior.fly()
    def walk(self):
        self.walk_behavior.walk()
    def talk(self):
        self.talk_behavior.talk()
    def projection(self):
        self.projection_behavior.projection()
print("Industrial Robot:")
industrialRobot = Robot(NonWalk(), NonTalk(), NonFly(), ProjectionInTwoD())
industrialRobot.fly()
industrialRobot.walk()
industrialRobot.talk()
industrialRobot.projection() 
print("\n=========================")
print("Dog Robot:")   
roboDog=Robot(NormalWalk(), NormalTalk(), NonFly(), ProjectionInThreeD())
roboDog.walk()
roboDog.talk()
roboDog.fly()
roboDog.projection()
print("\n=========================")
print("Sparrow:")   
sparrow=Robot(NonWalk(), NonTalk(), NormalFly(), ProjectionInThreeD())
sparrow.fly()
sparrow.walk()
sparrow.talk()
sparrow.projection()
