extends RigidBody2D

var speedTimer

signal hit

func _ready():
	$AnimatedSprite.playing = true
	var mobAnimationType = ["walking", "swimming", "flying"]
	$AnimatedSprite.animation = mobAnimationType[randi() %  mobAnimationType.size()]
	$VisibilityNotifier2D.connect("screen_exited", self, "clear_queue")

func clear_queue():
	queue_free()

func onHit(_body):
	hide()
	emit_signal("hit")
	$CollisionShape2D.set_deferred("disabled", true)


# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass
