;;; �ϥΥ�����
;;; n����Ĥ���from������to����tmp��Ȥäư�ư����
(defun myhanoi (n from to tmp)
  (cond ((= n 1)
         (format t "��~S��~S����~S��~%" n from to))  ; 1��ʤ���ľ�˰�ư�Ǥ���
        (t (myhanoi (- n 1) from tmp to)             ; ���n-1���ޤ�����
           (format t "��~S��~S����~S��~%" n from to) ; ���ֲ����Ĥ��ư
           (myhanoi (- n 1) tmp to from))))          ; ���򤷤�n-1����ư
