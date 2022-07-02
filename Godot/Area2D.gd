extends Area2D


export (int) var speed
var screensize
var rotate_dir = Vector2()
signal hit

func _ready():
	hide()
	screensize = get_viewport_rect().size
	self.connect("body_entered", self, "onHit")
	
func _process(delta):
	var velocity = Vector2()
	
	if Input.is_action_pressed("ui_left"):
		velocity.x -= 1
		rotate_dir.y = -1
	if Input.is_action_just_released("ui_left")  and rotate_dir.length() > 1:
		rotate_dir.y = 0
		
	if Input.is_action_pressed("ui_right"):
		velocity.x += 1
		rotate_dir.y = 1
	if Input.is_action_just_released("ui_right")  and rotate_dir.length() > 1:
		rotate_dir.y = 0
		
	if Input.is_action_pressed("ui_down"):
		velocity.y += 1
		rotate_dir.x = -1
	if Input.is_action_just_released("ui_down") and rotate_dir.length() > 1:
		rotate_dir.x = 0
	
	if Input.is_action_pressed("ui_up"):
		velocity.y -= 1
		rotate_dir.x = 1
	if Input.is_action_just_released("ui_up")  and rotate_dir.length() > 1:
		rotate_dir.x = 0
	
	if velocity.length() > 0:
		velocity = velocity.normalized() * speed
		$AnimatedSprite.play()
	else:
		$AnimatedSprite.stop()
		
	position += velocity * delta
	position.x = clamp(position.x, 0, screensize.x)
	position.y = clamp(position.y, 0, screensize.y)
	rotation = rotate_dir.angle()

func start(pos):
	position = pos
	show()
	$CollisionShape2D.disabled = false

func onHit(body):
	hide()
	emit_signal("hit")
	$CollisionShape2D.set_deferred("disabled", true)
