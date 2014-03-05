<?php
/**
 * @file
 * Theme template for jdt_user_notes template
 */

?>

<div class='jdt-user-notes-<?php print $note->note_id ?>'>
  <?php print $note->note_text ?><br />
  <i>by <?php print $username ?></i><br />
  <a href='../../note/<?php print $note->note_id ?>/edit'>Edit</a>
  <br /><br />
</div>
