<?php
$relate_node = wxjs_prev_next_node($node, array($node->type));
if($relate_node['prev']){
	$prev = l('« 上一篇','node/'.$relate_node['prev']['nid']);
}else{
	$prev = '<a href="###">没有了</a>';
}
if($relate_node['next']){
	$next = l('下一篇 »','node/'.$relate_node['next']['nid']);
}else{
	$next = '<a href="###">没有了</a>';
}
?>
<div class="prev-next-post clearfix">
  <div class="group previous">
    <?php echo $prev;?>
  </div>
  <div class="group next">
    <?php echo $next;?>
  </div>
</div>
