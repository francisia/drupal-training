<?php
/**
 * @file
 * Theme template for jdt_user_notes template
 */

?>

<div class='jdt-user-notes-<?php print $note->note_id ?>'>
  <?php print check_plain($note->note_text) ?><br />
  <?php print $edit_link ?>
  <br /><br />
</div>
