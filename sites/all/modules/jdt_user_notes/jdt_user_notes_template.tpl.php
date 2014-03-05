<?php
/**
 * @file
 * Theme template for jdt_user_notes template
 */

?>

<div class='jdt-user-notes-<?php print $note->note_id ?>'>
  <?php print check_plain($note->note_text) ?><br />
  <i>by <?php print check_plain($username) ?></i><br />
  <a href='../../note/<?php print $note->note_id ?>/edit'>Edit</a>
  <br /><br />
</div>
