using System;

class TalkAble
{
    public virtual void Talk() { }
}

class WalkAble
{
    public virtual void Walk() { }
}

class FlyAble
{
    public virtual void Fly() { }
}

class NormalTalkAble : TalkAble
{
    public override void Talk()
    {
        Console.WriteLine("Talking normally");
    }
}

class NotTalkAble : TalkAble
{
    public override void Talk()
    {
        Console.WriteLine("Cannot talk");
    }
}

class NormalWalkAble : WalkAble
{
    public override void Walk()
    {
        Console.WriteLine("Walking on two legs");
    }
}

class NotWalkAble : WalkAble
{
    public override void Walk()
    {
        Console.WriteLine("Cannot walk");
    }
}

class NormalFlyAble : FlyAble
{
    public override void Fly()
    {
        Console.WriteLine("Flying with wings");
    }
}

class NotFlyAble : FlyAble
{
    public override void Fly()
    {
        Console.WriteLine("Cannot fly");
    }
}

class Robot
{
    string RobId;
    string name;
    FlyAble flyingBehavior;
    WalkAble walkingBehavior;
    TalkAble talkingBehavior;

    public Robot(string name, string id, FlyAble p, WalkAble wk, TalkAble tal)
    {
        this.RobId = id;
        this.flyingBehavior = p;
        this.walkingBehavior = wk;
        this.talkingBehavior = tal;
        this.name = name;
    }

    public void printInfo()
    {
        Console.WriteLine("Robot: " + this.name + " (ID: " + this.RobId + ")");
    }

    public virtual void fly()
    {
        flyingBehavior.Fly();
    }

    public virtual void walk()
    {
        walkingBehavior.Walk();
    }

    public virtual void talk()
    {
        talkingBehavior.Talk();
    }
}

class UI
{
    public static void LinerDraw()
    {
        Console.Write("===========================================");
    }

    public static void spaceDraw(int n = 1)
    {
        for (int i = 0; i < n; i++)
        {
            Console.Write(" ");
        }
    }

    public static void newLineDraw(int n = 1)
    {
        for (int i = 0; i < n; i++)
        {
            Console.WriteLine();
        }
    }
}

class Program
{
    static void Main(string[] args)
    {
        FlyAble flyingBehavior = new NormalFlyAble();
        WalkAble walkingBehavior = new NormalWalkAble();
        TalkAble talkingBehavior = new NormalTalkAble();

        UI.LinerDraw();
        Robot robot = new Robot("Jimmy", "rob12", flyingBehavior, walkingBehavior, talkingBehavior);
        robot.printInfo();
        robot.talk();
        robot.talk();
        robot.fly();
        UI.newLineDraw(3);

        FlyAble dogFlyingBehavior = new NotFlyAble();
        WalkAble dogWalkingBehavior = new NormalWalkAble();
        TalkAble dogTalkingBehavior = new NormalTalkAble();
        Robot dog = new Robot("Tiger", "dog32", dogFlyingBehavior, dogWalkingBehavior, dogTalkingBehavior);
        dog.printInfo();
        dog.fly();
        dog.walk();
        dog.talk();
    }
}