(ql:quickload :lispbuilder-sdl)
(ql:quickload :lispbuilder-sdl-gfx)
(ql:quickload :lispbuilder-sdl-ttf)

(defvar *font-path* "/usr/share/fonts/truetype/sazanami/sazanami-mincho.ttf")
(defvar *font-size* 30)

(defun get-font ()
  (make-instance 'sdl:ttf-font-definition
                 :size *font-size*
                 :filename (sdl:create-path *font-path*)))

(defclass <pos> ()
  ((x :initform 0 :initarg :x :accessor x)
   (y :initform 0 :initarg :y :accessor y)))

(defclass <area> (<pos>)
 ((y2 :initform 0 :initarg :y2 :accessor y2)))

(defmethod collision-p ((pos <pos>) (area <area>))
  (and (= (x pos) (x area))
       (<= (y area) (y pos) (y2 area))))

(defun gen-random-hari (xpos)
  (let ((random-y (+ 160 (random 75)))
	(random-hole-size (+ 20 (random 10))))
  (make-instance '<area>
     :x xpos :y random-y :y2 (+ random-hole-size random-y))))

(defun ito ()
  (let* ((ito-pos (make-instance '<pos>
                      :x 300 :y 240))
	 (hari-list (list (gen-random-hari 480)))
 	(hari-speed 1)
	 (score 0)
	 (curr-hari (car hari-list)))
  (sdl:with-init ()
    (sdl:window 600 480 :title-caption "Ito")
    (sdl:clear-display sdl:*black*)
    (sdl:enable-key-repeat 1 1)
    (sdl:initialise-default-font (get-font))
    (sdl:with-events ()
      (:quit-event () t)
      (:key-down-event ()
        (decf (y ito-pos) (1+ hari-speed)))
      (:idle ()
	(sdl:clear-display sdl:*black*)
	(sdl-gfx:draw-circle-* (x ito-pos) (y ito-pos) 3 :color sdl:*white*)
	(sdl-gfx:draw-string-solid-* (format nil "Score: ~A" score) 400 30)
	(loop for hari in hari-list
		do
		(sdl-gfx:draw-box-* (x hari) (- (y hari) 10)
				    5
				    (- 480 (y hari) 10) :color sdl:*white*)
		(sdl-gfx:draw-box-* (x hari) (y hari) 5 (- (y2 hari) (y hari))
		 :color sdl:*blue*))
	(incf (y ito-pos) hari-speed)
	(loop for hari in hari-list
		do
		(decf (x hari) hari-speed))
	(when (= (x curr-hari) 300)
	  (if (not (collision-p ito-pos curr-hari))
		(sdl:push-quit-event)
		(progn (push (gen-random-hari 480) hari-list)
			(incf score 5)
			(setf hari-speed (1+ (truncate score 30)))
			(setf curr-hari (car hari-list)))))
        (sdl:update-display))))))