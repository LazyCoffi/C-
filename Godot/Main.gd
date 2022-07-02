extends Node

export(PackedScene) var mob_scene
export(PackedScene) var trap_scene

var score

func randn(a, b):
	return randi() % int(b) + int(a)

func _ready():
	$Player.connect("hit", self, "gameover")
	$MobTimer.connect("timeout", self, "mobTimerTimeout")
	$StartTimer.connect("timeout", self, "gameStart")
	$ScoreTimer.connect("timeout", self, "scoreAdd")
	$TrapTimer.connect("timeout", self, "trapTimerTimeout")
	$TrapTimer.start(randn(3, 6))
	randomize()
	newGame()

func trapTimerTimeout():
	var trap = trap_scene.instance()
	var screen_size = get_viewport().size
	trap.set_position(Vector2(randn(0, screen_size.x), randn(0, screen_size.y)))
	add_child(trap)
	trap.connect("body_entered", self, "kill")
	trap.connect("area_entered", self, "kill")
	$TrapTimer.start(randn(3, 6))

func kill(body):
	body.call("onHit", body)

func mobTimerTimeout():
	var mob = mob_scene.instance()

	var mob_spawn_location = get_node("MobPath/MobSpawnLocation")
	mob_spawn_location.offset = randi()

	var direction = mob_spawn_location.rotation + PI / 2

	print(mob_spawn_location.position)

	mob.position = mob_spawn_location.position

	direction += rand_range(-PI / 4, PI / 4)
	mob.rotation = direction

	var velocity = Vector2(rand_range(150.0, 250.0), 0.0)
	mob.linear_velocity = velocity.rotated(direction)

	add_child(mob)

func gameover():
	$ScoreTimer.stop()
	$MobTimer.stop()
	get_tree().quit()

func gameStart():
	$MobTimer.start()
	$ScoreTimer.start()

func scoreAdd():
	score += 1

func newGame():
	score = 0
	$Player.start($StartPosition.position)
	$StartTimer.start()
